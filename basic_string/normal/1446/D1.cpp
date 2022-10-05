#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],n,m,ans,c[N],pr[N],nx[N],id,vv[N*2],ww[N*2],*v=vv+N,*w=ww+N;
basic_string<int>g[N];
set<int>sm,s,d;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,l=0,t,k;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],g[a[i]]+=i,++c[a[i]];
	for(i=1;i<=n;++i)if(c[i]>c[m])m=i;
	for(i=1;i<=n;++i)if(a[i]==m)pr[i]=l,nx[l]=i,l=i,sm.insert(i);
	for(i=1;i<=n;++i)if(i!=m&&g[i].size()){
		d={},s=set<int>(begin(g[i]),end(g[i])),l=0;
		for(int o:g[i]){
			auto u=sm.upper_bound(o);
			if(u==sm.end())break;
			d.insert(*u),s.insert(*u),sm.erase(u);
		}
		for(int o:d)sm.insert(o);
		d={};
		for(int j=g[i].size()-1;~j;--j){
			auto u=sm.upper_bound(g[i][j]);
			if(u==sm.begin())break;
			--u,d.insert(*u),s.insert(*u),sm.erase(u);
		}
		for(int o:d)sm.insert(o);
		for(int o:s){
			if(!l||(a[o]==m&&a[l]==m&&pr[o]!=l)){
				if(v[t=0]=++id,a[o]==m)w[t]=pr[o]+1;
				else w[t]=1;
			}else if(v[t]<id)v[t]=id,w[t]=l+1;
			if(a[o]==m)++t;else --t;
			if(v[t]==id){
				auto u=s.upper_bound(o);
				if(u==s.end())k=n;else k=*u-1;
				if(a[o]==m&&nx[o])k=min(k,nx[o]-1);
				ans=max(ans,k-w[t]+1);
			}
			l=o;
		}
	}
	cout<<ans;
}