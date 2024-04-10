#include<bits/stdc++.h>
#define N 10001000
using namespace std;
int lpf[N],mob[N],lgt[N];
int prm[N],pcnt;
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int tmp=n/i;
		if(!lpf[i]){
			prm[pcnt++]=i;
			lpf[i]=i;
			mob[i]=1;
			tmp--;
		}
		else lgt[lpf[i]]++;
		ans-=1LL*mob[i]*tmp*(tmp-1)/2;
		for(int j=0;j<pcnt&&prm[j]<=n/i;j++){
			lpf[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
			mob[i*prm[j]]=-mob[i];
		}
	}
	ans+=1LL*(n-1-pcnt)*(n-2-pcnt);
	for(int i=n-1;i>=1;i--){
		lgt[i]+=lgt[i+1];
	}
	for(int i=0;i<pcnt&&prm[i]*2<=n;i++){
		ans+=(n-1-pcnt)*2;
		ans-=(n/prm[i]-1);
		ans+=lgt[n/prm[i]+1];
	}
	while(pcnt>0&&prm[pcnt-1]*2>n) pcnt--;
	ans+=1LL*pcnt*(pcnt-1)/2*3;
	int j=0;
	for(int i=pcnt-1;i>=0;i--){
		while(j<pcnt&&1LL*prm[i]*prm[j]<=n) j++;
		ans-=min(j,i);
	}
	printf("%lld\n",ans);
	return 0;
}