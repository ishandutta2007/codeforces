/*
	Author : Alex_Wei
	Problem : CF786B Legacy
	Powered by C++11
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
#define pii pair <int,int>
#define pll pair <ll,ll>
#define fi first
#define se second

const int N=1e5+5;
int n,q,s,a[N],in[N],out[N];
int tp,p,ql,qr,w;
vector <pii> e[N<<3];

void build(int l,int r,int fa,int x){
	if(x>1)e[fa].pb({x,0}),e[x+n*4].pb({fa+n*4,0});
	if(l==r)return in[l]=x,out[l]=x+n*4,void();
	build(l,l+r>>1,x,x<<1),build((l+r>>1)+1,r,x,x<<1|1);
} void con(int l,int r,int x){
	if(ql<=l&&r<=qr){
		if(tp==2)e[out[p]].pb({x,w});
		else e[x+n*4].pb({in[p],w});
		return;
	} int m=l+r>>1;
	if(ql<=m)con(l,m,x<<1);
	if(m<qr)con(m+1,r,x<<1|1); 
}

ll dis[N<<3],vis[N<<3];
priority_queue <pll,vector<pll>,greater<pll> > d;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[in[s]]=0,d.push({0,in[s]});
	while(!d.empty()){
		pll t=d.top(); d.pop();
		ll id=t.se,ds=t.fi;
		if(vis[id])continue;
		vis[id]=1;
		for(pii it:e[id])if(dis[it.fi]>ds+it.se)
			dis[it.fi]=ds+it.se,d.push({dis[it.fi],it.fi});
	}
}

int main(){
	cin>>n>>q>>s,build(1,n,0,1);
	for(int i=1;i<=q;i++){
		cin>>tp;
		if(tp==1)cin>>p>>ql>>w,e[out[p]].pb({in[ql],w});
		else cin>>p>>ql>>qr>>w,con(1,n,1);
	} for(int i=1;i<=n;i++)e[in[i]].pb({out[i],0}),e[out[i]].pb({in[i],0});
	dijkstra(s);
	for(int i=1;i<=n;i++)cout<<(dis[in[i]]<1e18?dis[in[i]]:-1)<<" ";
	return 0;
}