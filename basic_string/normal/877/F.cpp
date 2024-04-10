#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
using ll=long long;
int a[N],t[N],u[N],v[N],w[N],id,tu[N*3],tv[N*3];
ll s[N],ans[N];
map<ll,int>mp;
int get(ll x){
	if(!mp[x])mp[x]=++id;
	return mp[x];
}
struct Q{
	int l,r,i,b;
}o[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,k,i,b,q,l=1,r=0;
	ll now=0;
	for(cin>>n>>k,i=1;i<=n;++i)cin>>t[i];
	for(i=1;i<=n;++i)if(cin>>a[i],t[i]==2)a[i]=-a[i];
	for(i=1,w[0]=get(0);i<=n;++i)s[i]=s[i-1]+a[i],u[i]=get(s[i]-k),v[i]=get(s[i-1]+k),w[i]=get(s[i]);
	for(cin>>q,b=n/sqrt(q)+1,i=1;i<=q;++i)cin>>o[i].l>>o[i].r,o[i].i=i,o[i].b=o[i].l/b;
	sort(o+1,o+q+1,[](Q a,Q b){return a.b<b.b||(a.b==b.b&&((a.b&1)?a.r<b.r:a.r>b.r));});
	for(i=1;i<=q;++i){
		while(l>o[i].l)--l,++tu[u[l]],++tv[v[l]],now+=tu[w[l-1]];
		while(r<o[i].r)++r,++tu[u[r]],++tv[v[r]],now+=tv[w[r]];
		while(l<o[i].l)now-=tu[w[l-1]],--tu[u[l]],--tv[v[l]],++l;
		while(r>o[i].r)now-=tv[w[r]],--tu[u[r]],--tv[v[r]],--r;
		ans[o[i].i]=now;
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
}