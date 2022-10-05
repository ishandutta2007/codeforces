#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=101,LOG=18,block=450;
ll mod,L,R,k,ans,n;
vector<ll> v;
pair< pair<ll,ll>,pair<ll,ll> > mult(pair< pair<ll,ll>,pair<ll,ll> >a,pair< pair<ll,ll>,pair<ll,ll> > b){
	return mp(mp((a.f.f*b.f.f+a.f.s*b.s.f)%mod,(a.f.f*b.f.s+a.f.s*b.s.s)%mod),mp((a.s.f*b.f.f+a.s.s*b.s.f)%mod,(a.s.f*b.f.s+a.s.s*b.s.s)%mod));
}
pair< pair<ll,ll>,pair<ll,ll> > binpow(ll p){
	if(p==1)
		return mp(mp(0,1),mp(1,1));
	pair< pair<ll,ll>,pair<ll,ll> > c=binpow(p/2);
	c=mult(c,c);
	if(p&1)
		c=mult(c,mp(mp(0,1),mp(1,1)));
	return c;
}
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    cin>>mod>>L>>R>>k;
	L--;
	ll l,r;
	l=1;
	while(l<=R){
		r=R/(R/l);
		v.pb(r);
		l=r+1;
	}
	l=1;
	while(l<=L){
		r=L/(L/l);
		v.pb(r);
		l=r+1;
	}	                    
	for(int i=0;i<v.size();i++)
		if( R/v[i]-L/v[i] >= k  )
			ans=max(ans,v[i]);
	cout<<binpow(ans).f.s%mod;
}