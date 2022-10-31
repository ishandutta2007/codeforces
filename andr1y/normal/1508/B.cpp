// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 1e5+228;
ll res[N];
bool ban[N];
void go(ll n, ll k){
    yree sz;
    for(ll i = 1;i<=n;i++) sz.insert(i), ban[i]=0;
    ban[0]=ban[n+1]=1;
    ll j=1LL<<(n-1);
    for(ll i = 0;i<n;i++){
        vector<ll> pa;
        for(ll e = 0;e<n-i;e++){
            auto it = sz.find_by_order(0);
            ll ee = *it;
            sz.erase(it);
            ban[ee]=1;
            pa.push_back(ee);
            ll ct = 1, bs=0;
            for(ll j = ee+1;j<=n+1;j++){
                if(ban[j]){
                    if(bs) ct*=(1LL<<(bs-1));
                    bs=0;
                }else bs++;
            }
            if(ct>k){
                reverse(pa.begin(), pa.end());
                for(auto j : pa){
                    res[i]=j;
                    i++;
                }
                i--;
                break;
            }else k-=ct;
        }
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        k--;
        ll j = 1;
        bool ok=1;
        for(ll i = 1;i<=n&&ok;i++){
            if(j>k) ok=0;
            else j<<=1;
        }
        if(ok){
            cout<<"-1\n";
            continue;
        }
        //nado pprociuvaty z last 61 symbol
        if(n<=61){
            go(n, k);
            for(ll i =0;i<n;i++) cout<<res[i]<<' ';
            cout<<'\n';
        }else{
            go(61, k);
            for(ll i = 0;i<n-61;i++) cout<<i+1<<' ';
            for(ll i =0;i<61;i++) cout<<n-61+res[i]<<' ';
            cout<<'\n';
        }
    }
}