#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
int n,a[400100],m,lim,res[400100];
pii mx;
pii f[400100],g[400100],seg[1600100];
vector<int>v;
vector<pii>q[400100];
pii operator +=(pii&x,const pii&y){
	if(x.ff==y.ff)(x.ss+=y.ss),x.ss%=mod;
	else if(x.ff<y.ff)x=y;
}
pii operator +(const pii&x,const pii&y){
	if(x.ff==y.ff)return make_pair(x.ff,(x.ss+y.ss)%mod);
	return max(x,y);
}
void modify(int x,int l,int r,int P,pii val){
	if(l>P||r<P)return;
	seg[x]+=val;
	if(l!=r)modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val);
}
pii query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return mp(0,0);
	if(L<=l&&r<=R)return seg[x];
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
void build(int x,int l,int r){
	seg[x]=mp(0,0);
	if(l!=r)build(lson,l,mid),build(rson,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),lim=v.size();
	for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),q[x].push_back(mp(y,i));
	build(1,1,lim);
	for(int i=1;i<=n;i++){
		f[i]=query(1,1,lim,1,a[i]-1),f[i].first++;
		if(f[i].first==1)f[i].second++;
		for(auto j:q[i])res[j.second]=query(1,1,lim,1,lower_bound(v.begin(),v.end(),j.first)-v.begin()).first+1;
		modify(1,1,lim,a[i],f[i]),mx+=f[i];
	}
	build(1,1,lim);
	for(int i=n;i>=1;i--){
		g[i]=query(1,1,lim,a[i]+1,lim),g[i].first++;
		if(g[i].first==1)g[i].second++;
		int fal=(f[i].first+g[i].first-1==mx.first&&1ll*f[i].second*g[i].second%mod==mx.second?mx.first-1:mx.first);
		for(auto j:q[i])res[j.second]+=query(1,1,lim,upper_bound(v.begin(),v.end(),j.first)-v.begin()+1,lim).first,res[j.second]=max(res[j.second],fal);
		modify(1,1,lim,a[i],g[i]);
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}
/*
15 14
76 9 32 82 40 91 46 5 12 69 44 97 30 13 29
4 73
13 84
14 51
5 99
7 47
14 32
4 12
11 20
9 65
15 95
10 26
5 25
2 62
11 81
*/