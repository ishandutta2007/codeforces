// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N];
ll e[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){cin>>a[i];}
        e[0]=a[0];
        ll sk = a[0];
        bool aok=1;
        multiset<ll> er[2];
        for(ll i = 1;i<n;i++){
            e[i] = a[i]-sk;
            sk=a[i]-sk;
            er[i&1].insert(e[i]);
            if(e[i]<0) aok=0;
        }
        if(aok&&e[n-1]==0){
            cout<<"YES\n";
            continue;
        }
        bool ok = 1, ff=0;
        for(ll i = 1;i<n&&ok;i++){
            er[i&1].erase(er[i&1].find(e[i]));
            ok=ok&&(e[i-1]>=0);
            ll k1 = 2*a[i-1]-2*a[i];
            ll k0 = 2*a[i]-2*a[i-1];
            ll m1 = (er[i&1].empty()?inf:*(er[i&1].begin()));
            ll m0 = (er[(i&1)^1].empty()?inf:*(er[(i&1)^1].begin()));
            ll et = (i>1?e[i-2]:0);
            ll fin = (i==n-1 ? a[i-1]-a[i]+et : (((n-1)&1)==(i&1) ? e[n-1]+k1 : e[n-1]+k0));
            if(a[i]-et>=0&&a[i-1]-a[i]+et>=0&&m0+k0>=0&&m1+k1>=0&&fin==0){
                cout<<"YES\n";
                ff=1;
                ok=0;
            }
        }
        if(!ff) cout<<"NO\n";
    }
}