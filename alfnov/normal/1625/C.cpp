#include<bits/stdc++.h>
using namespace std;
int d[10005],a[10005];
long long f[505][505];
int main(){
	int n,l,k;
	cin>>n>>l>>k;
	for(int i=1;i<=n;++i)cin>>d[i];
	d[n+1]=l;
	for(int i=1;i<=n;++i)cin>>a[i];
	memset(f,63,sizeof(f));
	f[1][0]=0;
	for(int i=2;i<=n+1;++i)for(int j=0;j<=k;++j){
		for(int l=1;l<i;++l)if((i-l-1)<=j){
			f[i][j]=min(f[i][j],f[l][j-(i-l-1)]+1ll*a[l]*(d[i]-d[l]));
		}
	}
	long long ans=3e18;
	for(int i=0;i<=k;++i)ans=min(ans,f[n+1][i]);
	cout<<ans<<endl;
	return 0;
}