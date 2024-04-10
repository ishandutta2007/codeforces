#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300005
using namespace std;
typedef long long ll;
struct compu{
	int c,id;
	bool operator < (const compu b)const
	{
		return c < b.c;
	}
}cc[maxn];
int n,x1,x2,y1,y2,s1[maxn],s2[maxn];
int l_b(double d){
	int lb = 1,rb = n+1;
	while(lb < rb){
		int mid = (lb + rb) >> 1;
		if(cc[mid].c >= d) rb = mid;
		else lb = mid+1;
	}
	return lb;
}
int main(){
	scanf("%d%d%d",&n,&x1,&x2);
	for(int i=1;i<=n;i++){
		scanf("%d",&cc[i].c);
		cc[i].id = i;
	}
	sort(cc+1,cc+n+1);
	for(int k1=1;k1<=n;k1++){
		s1[k1] = l_b(1.0 * x1 / k1);
	}
	for(int i=1;i<=n;i++){
		if(n - s1[i] + 1 < i) y2++;
		else break;
	}
	for(int k2=1;k2<=n;k2++){
		s2[k2] = l_b(1.0 * x2 / k2);
	}
	for(int i=1;i<=n;i++){
		if(n - s2[i] + 1 < i) y1++;
		else break;
	}
	for(int z = 0;z < n-1;z++){
		int st1 = n - z - 1 - y1, st2 = n - z - 1 - y2;
		if(st1 >= 1 && s1[st1] <= s2[n-z-st1] && n-s1[st1]+1 >= n-z){
			printf("Yes\n");
			printf("%d %d\n",st1,n - z - st1);
			for(int i=z+1;i<=n;i++){
				printf("%d ",cc[i].id);
				if(i-z == st1 || i == n) printf("\n");
			}
			return 0;
		}
		if(st2 >= 1 && s2[st2] <= s1[n-z-st2] && n-s2[st2]+1 >= n-z){
			printf("Yes\n");
			printf("%d %d\n",n - z - st2,st2);
			for(int i=z + st2 + 1;i<=n;i++) printf("%d ",cc[i].id);
			printf("\n");
			for(int i=z+1;i<=z + st2;i++){
				printf("%d ",cc[i].id);
			}
			printf("\n");
			return 0;
		}
	}
	puts("No");
	return 0;
}