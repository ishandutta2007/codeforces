#include<bits/stdc++.h>
using namespace std;
enum{N=300003,M=N*2,O=M*2};
struct F{
	int f,s1,s2;
}f[M],st[O];
int u,v,t,id[O];
long long ans;
pair<int,int>w;
int gf(int x){return f[x].f==x?x:gf(f[x].f);}
map<pair<int,int>,int>mp;
vector<pair<int,int>>e[O];
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return e[k].push_back(w);
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void mg(int x,int y){
	if(x=gf(x),y=gf(y),x==y)return;
	if(f[x].s1+f[x].s2>f[y].s1+f[y].s2)swap(x,y);
	st[++t]=f[x],id[t]=x,st[++t]=f[y],id[t]=y,ans-=f[x].s1*1ll*f[x].s2+f[y].s1*1ll*f[y].s2;
	f[x].f=y,f[y].s1+=f[x].s1,f[y].s2+=f[x].s2,ans+=f[y].s1*1ll*f[y].s2;
}
void wk(int k,int l,int r){
	int t2=t;
	auto a2=ans;
	for(auto o:e[k])mg(o.first,o.second+N);
	if(l==r)cout<<ans<<' ';else{
		int m=l+r>>1;
		wk(k*2,l,m),wk(k*2+1,m+1,r);
	}
	for(ans=a2;t>t2;--t)f[id[t]]=st[t];
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,j,k;
	cin>>q;
	for(i=1;i<=q;++i){
		cin>>j>>k;
		if(!mp[{j,k}])mp[{j,k}]=i;
		else u=mp[w={j,k}],v=i-1,upd(1,1,q),mp.erase(w);
	}
	for(auto o:mp)u=o.second,v=q,w=o.first,upd(1,1,q);
	for(i=0;i<M;++i)f[i]={i,i<N,i>=N};
	wk(1,1,q);
	return 0;
}