#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;
typedef long long ll;
int n,s,tim[maxn];
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		int h,m;
		scanf("%d%d",&h,&m);
		tim[i] = h * 60 + m;
	}
	if(tim[1] > s){
		printf("0 0\n");
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(tim[i] - tim[i-1] > s * 2 + 1){
			int t = tim[i-1] + s + 1;
			printf("%d %d\n",t/60,t%60);
			return 0;
		}
	}
	int t = tim[n] + s + 1;
	printf("%d %d\n",t/60,t%60);
	return 0;
}