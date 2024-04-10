#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],n,m,ans,c[N],pr[N],nx[N],id,vv[N*2],ww[N*2],*v=vv+N,*w=ww+N;
basic_string<int>g[N],p,p0,p1,p2;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,o,l=0,t,k,x;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],g[a[i]]+=i,++c[a[i]];
	for(i=1;i<=n;++i)if(c[i]>c[m])m=i;
	for(i=1;i<=n;++i){
		pr[i]=l;
		if(a[i]==m)l=i;
	}
	for(l=n+1,pr[l]=l,i=n;i;--i){
		nx[i]=l;
		if(a[i]==m)l=i;
	}
	for(i=1;i<=n;++i)if(i!=m&&g[i].size()){
		l=0,p1=p2={};
		for(int o:g[i]){
			l=max(nx[l],nx[o]);
			if(l>n)break;
			p1+=l;
		}
		l=n+1;
		for(j=g[i].size()-1;~j;--j){
			o=g[i][j],l=min(pr[l],pr[o]);
			if(!l)break;
			p2+=l;
		}
		reverse(begin(p2),end(p2)),p0.resize(p1.size()+p2.size()),merge(begin(p1),end(p1),begin(p2),end(p2),begin(p0));
		p.resize(g[i].size()+p0.size()),merge(begin(p0),end(p0),begin(g[i]),end(g[i]),begin(p)),l=0,x=p.size();
		for(j=0;j<x;++j){
			if(o=p[j],j+1<x&&o==p[j+1])continue;
			if(!l||(a[o]==m&&a[l]==m&&pr[o]!=l)){
				if(v[t=0]=++id,a[o]==m)w[t]=pr[o]+1;
				else w[t]=1;
			}else if(v[t]<id)v[t]=id,w[t]=l+1;
			if(a[o]==m)++t;else --t;
			if(v[t]==id){
				if(j+1<x)k=p[j+1]-1;else k=n;
				k=min(k,nx[o]-1),ans=max(ans,k-w[t]+1);
			}
			l=o;
		}
	}
	cout<<ans;
}