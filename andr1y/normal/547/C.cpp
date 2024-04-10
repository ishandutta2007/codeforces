// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+1;
ll a[2*N];
ll cnt[5*N];
vector<ll> ud[2*N];
bool an[2*N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
	    cin >> a[i];
	    ll e = a[i], u=1;
	    for(ll j = 2;j*j<=e;j++){
	        if(e%j==0){
	            u*=j;
	            while(e%j==0) e/=j;
	            ud[i].push_back(j);
	        }
	    }
	    if(e>1) u*=e, ud[i].push_back(e);
	    a[i]=u;
	}
	ll res=0, ts=0;
	while(m--){
	    ll p;cin>>p;--p;
	    ll kf=1;
	    if(an[p])kf=-1;
	    an[p]=!an[p];
	    if(a[p]!=1){
	        ll nok=0;
    	    for(ll mask=1;mask<(1<<ud[p].size());mask++){
    	        ll k =1;
    	        for(ll i=0;i<ud[p].size();i++) if((mask>>i)&1) k*=ud[p][i];
    	        nok+=(__builtin_popcount(mask)&1 ? 1:-1)*cnt[k];
    	        cnt[k]+=kf;
    	    }
    	    //cout<<"~"<<nok<<endl;
    	    nok=ts-nok;
    	    res+=nok*kf;
	    }else{
	        if(kf==-1) res-=ts-1;
	        else res+=ts;
	    }
	    ts+=kf;
	    cout<<res<<'\n';
	}
}