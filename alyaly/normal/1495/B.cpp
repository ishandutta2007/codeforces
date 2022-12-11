#include<bits/stdc++.h>
#define N 200000
using namespace std;
int n,a[N+1],p[N+1],dp[N+1],ap[2][N+1],ans,fl[N+1],lp[2][N+1],pr[N+1],su[N+1],f[N+1],nd[N+1],dfp[N+1],afp[2][N+1],lfp[2][N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],a[p[i]]=i;
	for(int i=n;i>=1;i--){
		if(p[a[i]-1]>i&&a[i]>1)afp[0][i]=dfp[p[a[i]-1]]+1;else afp[0][i]=1;
		if(p[a[i]+1]>i&&a[i]<n)afp[1][i]=dfp[p[a[i]+1]]+1;else afp[1][i]=1;
		dfp[i]=max(afp[0][i],afp[1][i]);
		f[a[i]]=dfp[i];
	}
	for(int i=1;i<=n;i++){
		if(p[a[i]-1]<i&&a[i]>1)ap[0][i]=dp[p[a[i]-1]]+1,lp[0][i]=lp[0][p[a[i]-1]];else lp[0][i]=a[i],ap[0][i]=1;
		if(p[a[i]+1]<i&&a[i]<n)ap[1][i]=dp[p[a[i]+1]]+1,lp[1][i]=lp[1][p[a[i]+1]];else lp[1][i]=a[i],ap[1][i]=1;
		dp[i]=max(ap[0][i],ap[1][i]);
		if(ap[0][i]==ap[1][i]&&ap[0][i]%2==1)fl[i]=0;
		else fl[i]=1;
	}
	for(int i=1;i<=n;i++)pr[i]=max(pr[i-1],f[i]);
	for(int i=n;i>=1;i--)su[i]=max(su[i+1],f[i]);
	for(int i=1;i<=n;i++){
		if(max(max(pr[lp[0][i]-1],su[lp[1][i]+1]),max(afp[1][p[lp[1][i]]],afp[0][p[lp[0][i]]]))>=dp[i])fl[i]=1;
		if(!fl[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
1 2 5 4 3 6 7
*/