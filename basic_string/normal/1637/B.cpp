#include<bits/stdc++.h>
using namespace std;
enum{N=109};
int a[N],f[N][N];
bool v[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,now;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)a[i]=min(a[i],102);
		for(i=1;i<=n;++i)for(j=i,now=0,memset(v,0,sizeof v);j<=n;++j){
			v[a[j]]=1;
			while(v[now])++now;
			f[i][j]=1+now;
		}
		for(i=n;i;--i)for(j=i;j<=n;++j){
			for(k=i;k<j;++k)f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
		}
		int ans=0;
		for(i=1;i<=n;++i)for(j=i;j<=n;++j)ans+=f[i][j];
		cout<<ans<<'\n';
	}
	return 0;
}