#include<cstdio>
#include<iostream>
using namespace std;
#define N 200100
int cnt[N][63],a[N],sum[63];
int main(){
	int n,k,m,x;
	long long r=1,ans=0;
	scanf("%d%d%d",&n,&k,&m);
	while(k--) r*=m;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a[i]=x;
		while(x){
			int b=__lg(x&-x);
			cnt[i][b]++;
			sum[b]++;
			x^=x&-x;
		}
	}
	for(int i=0;i<n;i++){
		long long tmp=0;
		for(int j=0;j<63;j++){
			if(sum[j]>cnt[i][j]) tmp|=(1LL<<j);
		}
		if((tmp|a[i]*r)>ans) ans=tmp|a[i]*r;
	}
	printf("%I64d\n",ans);
	return 0;
}