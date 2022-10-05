#include<bits/stdc++.h>
using namespace std;
#define I int k,int l,int r
#define _ s[k],s[k*2],s[k*2+1]
#define M int m=(l+r)>>1;
#define L k*2,l,m
#define R k*2+1,m+1,r
enum{N=100009};
basic_string<int>g[N];
vector<pair<int,int>>qu[N];
int ans[N],u,i;
struct T{
	int a,a2;
}s[262149];
auto dn=[](T&k,T&a,T&b){
	int w=max(a.a,b.a);
	if(k.a>w){
		if(a.a==w)a.a=k.a;
		if(b.a==w)b.a=k.a;
	}
};
auto up=[](T&k,T&a,T&b){
	if(a.a>b.a)k.a=a.a,k.a2=max(a.a2,b.a);
	else if(a.a<b.a)k.a=b.a,k.a2=max(a.a,b.a2);
	else k.a=a.a,k.a2=max(a.a2,b.a2);
};
void bd(I){
	if(l==r){s[k].a=l;return;}
	M bd(L),bd(R),up(_);
}
void upd(I){
	if(s[k].a<u)return;
	if(r<=u&&s[k].a2<u){s[k].a=i;return;}
	M if(dn(_),upd(L),m<u)upd(R);up(_);
}
int qry(I){
	if(l==r)return s[k].a;
	M return dn(_),u<=m?qry(L):qry(R);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,q,j,k;
	for(cin>>n>>m;m--;)cin>>i>>j,g[j]+=i;
	for(cin>>q,i=1;i<=q;++i)cin>>j>>k,qu[k].push_back({j,i});
	for(bd(1,1,n),i=1;i<=n;++i){
		for(int o:g[i])u=o,upd(1,1,n);
		for(auto o:qu[i])u=o.first,ans[o.second]=qry(1,1,n);
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
}