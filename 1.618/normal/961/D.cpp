#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define inf 0x3f3f3f3f
#define eps 1e-10
using namespace std;
typedef long long ll;
struct point{
	int x,y;
}p[maxn];
int n;
double k,b;
bool covered[maxn];
inline void calc(int p1,int p2){
	k = 1.0*(p[p2].y-p[p1].y) / (p[p2].x - p[p1].x);
	b = 1.0*p[p2].y - p[p2].x * k;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	if(n<=2){
		puts("YES");
		return 0;
	}
	for(int r1=1;r1<=2;r1++){
		for(int r2=r1+1;r2<=3;r2++){
			memset(covered,false,sizeof(covered));
			if(p[r1].x != p[r2].x){
				calc(r1,r2);
				for(int i=1;i<=n;i++){
					if(abs(p[i].x * k + b - 1.0 * p[i].y) < eps) covered[i] = true;
				}
			}else{
				for(int i=1;i<=n;i++){
					if(p[i].x == p[r1].x) covered[i] = true;
				}
			}
			int n1,n2;
			n1 = n2 = -1;
			for(int i=1;i<=n;i++){
				if(!covered[i]){
					if(n1==-1) n1 = i;
					else{
						n2 = i;
						break;
					}
				}
			}
			if(n2 == -1){
				puts("YES");
				return 0;
			}
			if(p[n1].x != p[n2].x){
				calc(n1,n2);
				for(int i=1;i<=n;i++){
					if(abs(p[i].x * k + b - 1.0 * p[i].y) < eps) covered[i] = true;
				}
			}else{
				for(int i=1;i<=n;i++){
					if(p[i].x == p[n1].x) covered[i] = true;
				}
			}
			bool fl = true;
			for(int i=1;i<=n;i++){
				if(!covered[i]){
					fl = false;
					break;
				}
			}
			if(fl){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}