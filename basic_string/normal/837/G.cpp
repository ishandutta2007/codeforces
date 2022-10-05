#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=200009};
struct T{
	int l,r,a;
	ll b;
}s[N*21];
int rt[N],id,u,v,a,b;
ll w;
vector<tuple<int,int,int>>p[N];
void upd(int&k,int l,int r){
	if(s[++id]=s[k],k=id,l==r){
		s[k].a=a,s[k].b=b;
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(s[k].l,l,m);else upd(s[k].r,m+1,r);
	s[k].a=s[s[k].l].a+s[s[k].r].a,s[k].b=s[s[k].l].b+s[s[k].r].b;
}
void qry(int k,int l,int r){
	if(!k)return;
	if(u<=l&&r<=v){w+=s[k].a*1ll*a+s[k].b;return;}
	int m=l+r>>1;
	if(u<=m)qry(s[k].l,l,m);
	if(m<v)qry(s[k].r,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,n,m,x1,x2,y1,y2;
	for(cin>>n,i=1;i<=n;++i){
		cin>>x1>>x2>>y1>>a>>b>>y2;
		p[0].push_back({i,0,y1});
		p[x1+1].push_back({i,a,b});
		p[x2+1].push_back({i,0,y2});
	}
	for(i=0;i<N;++i){
		if(i)rt[i]=rt[i-1];
		for(auto o:p[i])tie(u,a,b)=o,upd(rt[i],1,n);
	}
	for(cin>>m;m--;cout<<w<<'\n')cin>>u>>v>>a,a=min((a+w)%(int)1e9,N-1ll),w=0,qry(rt[a],1,n);
}