#include<bits/stdc++.h>
using namespace std;
enum{N=109,M=N*N*2};
bool f[M],g[M];
int a[N],b[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,sum=0,ans=0,u;
	for(cin>>T;T--;){
		cin>>n;
		memset(f,0,sizeof f),f[0]=1;ans=sum=0;
		for(i=1;i<=n;++i)cin>>a[i],sum+=a[i],ans+=a[i]*a[i];
		for(i=1;i<=n;++i)cin>>b[i],sum+=b[i],ans+=b[i]*b[i]; 
		ans*=n-2;
		for(i=1;i<=n;++i){
			memset(g,0,sizeof g);
			for(j=M-1;~j;--j)if(f[j])g[j+a[i]]=g[j+b[i]]=1;
			memcpy(f,g,sizeof f);
		}
		u=1e9;
		for(i=0;i<M;++i)if(f[i])u=min(u,i*i+(sum-i)*(sum-i));
		cout<<u+ans<<'\n';
	}
	return 0;
}