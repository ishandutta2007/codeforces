#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct F{
	int f,s;
}f[N*2];
vector<pair<int,int>>e[N*4];
map<pair<int,int>,int>mp;
pair<int,int>p;
int u,v,n,tp,sx[N*2],sy[N*2];
bool ans[N];
void add(int k,int l,int r){
	if(u<=l&&r<=v)return e[k].push_back(p);
	int m=l+r>>1;
	if(u<=m)add(k*2,l,m);
	if(m<v)add(k*2+1,m+1,r);
}
int gf(int x){return f[x].f==x?x:gf(f[x].f);}
void mg(int x,int y){
	if(f[x].s>f[y].s)swap(x,y);
	sx[++tp]=x,sy[tp]=y,f[y].s+=f[x].s,f[x].f=y;
}
void work(int k,int l,int r){
	bool b=1;
	int m=l+r>>1,o=tp,u,v;
	for(auto i:e[k]){
		u=gf(i.first),v=gf(i.second);
		if(u==v){b=0;break;}
		mg(u,gf(i.second+n)),mg(gf(i.first+n),v);
	}
	if(l==r)ans[l]=b;
	else if(b)work(k*2,l,m),work(k*2+1,m+1,r);
	for(;tp>o;--tp)f[sx[tp]].f=sx[tp],f[sy[tp]].s-=f[sx[tp]].s;
}
int main(){
	int q,i,j,k;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n*2;++i)f[i].f=i,f[i].s=1;
	for(i=1;i<=q;++i){
		scanf("%d%d",&j,&k);
		if(mp[p={j,k}])u=mp[p],v=i-1,add(1,1,q),mp[p]=0;else mp[p]=i;
	}
	for(auto o:mp)if(u=o.second)p=o.first,v=q,add(1,1,q);
	work(1,1,q);
	for(i=1;i<=q;++i)puts(ans[i]?"YES":"NO");
	return 0;
}