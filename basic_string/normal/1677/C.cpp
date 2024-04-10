#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],b[N],to[N];
bool vis[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,n,j,k,l;
	long long ans;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],to[a[i]]=i;
		for(i=1;i<=n;++i)cin>>b[i],b[i]=to[b[i]];
		l=0;
		memset(vis,0,n+1);
		for(i=1;i<=n;++i)if(!vis[i]){
			j=i;
			k=0;
			while(!vis[j])++k,vis[j]=1,j=b[j];
			if(k&1)++l;
		}
		l=(n-l)/2;ans=0;
		for(i=1;i<=l;++i)ans-=i*2;
		for(i=1;i<=l;++i)ans+=(n-i+1)*2;
		cout<<ans<<'\n';
	}
}
//max sum |b[a[i]]-b[i]|
//2l ll
//2l+1  l l