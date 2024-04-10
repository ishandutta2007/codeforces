#include<bits/stdc++.h>
#define N 1001000
#define Q 1000000007
using namespace std;
int cnt[N][20];
int prm[N],pcnt;
bool notp[N];
int main(){
	int T,r,n;
	cnt[0][0]=1;
	for(int i=1;i<20;i++) cnt[0][i]=2;
	for(int i=1;i<N;i++){
		cnt[i][0]=1;
		for(int j=1;j<20;j++){
			cnt[i][j]=(cnt[i-1][j]+cnt[i][j-1])%Q;
		}
	}
	for(int i=2;i<N;i++){
		if(!notp[i]) prm[pcnt++]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			notp[i*prm[j]]=true;
			if(i%prm[j]==0) break;
		}
	}
	scanf("%d",&T);
	while(T--){
		int ans=1;
		scanf("%d%d",&r,&n);
		for(int i=0;prm[i]*prm[i]<=n;i++){
			if(n%prm[i]==0){
				int e=0;
				while(n%prm[i]==0){
					n/=prm[i];
					e++;
				}
				ans=1LL*ans*cnt[r][e]%Q;
			}
		}
		if(n>1) ans=1LL*ans*cnt[r][1]%Q;
		printf("%d\n",ans);
	}
	return 0;
}