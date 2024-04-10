#include<bits/stdc++.h>
#define N 2010
using namespace std;
long long force[N][N];
long long dp[N];
int l[N],r[N];
long long m[N];
void upd(long long &x, long long y){
	if(x==-1 || y<x) x=y;
}
int main(){
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%d%d%lld",&l[i],&r[i],&m[i]);
	memset(force,-1,sizeof(force));
	for(int i=0;i<n;i++){
		long long pre=0;
		for(int j=i;j<n;j++){
			if(k*(r[j]-l[j]+1)<pre+m[j]) break;
			if(j==n-1) force[i][j]=0;
			else{
				int tr=min(r[j],l[j+1]-1);
				long long rem=(pre+m[j])%k;
				if(k*(tr-l[j]+1)>=pre+m[j]){
					force[i][j]=rem?k-rem:0;
					pre=rem;
				}
				else{
					pre=rem?rem:k;
				}
			}
		}
	}
	for(int i=0;i<n;i++) dp[i]=-1;
	dp[n]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(force[i][j]>=0 && dp[j+1]>=0) upd(dp[i],dp[j+1]+force[i][j]);
		}
	}
	if(dp[0]>=0){
		for(int i=0;i<n;i++) dp[0]+=m[i];
	}
	printf("%lld\n",dp[0]);
	return 0;
}