#include<bits/stdc++.h>
using namespace std;
enum{N=100003,M=1003};
int a2[N],a[N],bg[N],ed[N],id,m,u,v,w;
basic_string<int>g[N];
bitset<M>pr;
struct T{
	bitset<M>b;
	int a;
}s[262199],ans;
bool chk(int x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
void dfs(int x,int y){
	bg[x]=++id,a[id]=a2[x]%m;
	for(int i:g[x])if(i^y)dfs(i,x);
	ed[x]=id;
}
inline void add(T&k,int w){
	if(!w)return;
	k.b=(k.b<<w)|(k.b>>m-w);
	if(k.a+=w,k.a>=m)k.a-=m;
}
inline void mg(T&k,const T&a,const T&b){
	int o=k.a;
	k.a=0,k.b=a.b|b.b,add(k,o);
}
void bd(int k,int l,int r){
	if(l==r){s[k].b[a[l]]=1;return;}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),mg(s[k],s[k*2],s[k*2+1]);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return add(s[k],w);
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
	mg(s[k],s[k*2],s[k*2+1]);
}
T qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1;T tmp;tmp.a=0;
	if(u<=m&&m<v){
		mg(tmp,qry(k*2,l,m),qry(k*2+1,m+1,r));
		add(tmp,s[k].a);
		return tmp;
	}
	if(u<=m){tmp=qry(k*2,l,m);add(tmp,s[k].a);return tmp;}
	tmp=qry(k*2+1,m+1,r),add(tmp,s[k].a);return tmp;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,x,q;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>a2[i];
	for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	dfs(1,0);
	for(i=2;i<m;++i)if(chk(i))pr[i]=1;
	bd(1,1,n);
	cin>>q;
	while(q--)if(cin>>i>>j,i==1){
		cin>>x,u=bg[j],v=ed[j],w=x%m,upd(1,1,n);
	}else{
		u=bg[j],v=ed[j],ans=qry(1,1,n);
		cout<<(ans.b&pr).count()<<'\n';
	}
	return 0;
}