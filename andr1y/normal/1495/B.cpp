// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], edl[N], edr[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> uws;
    ll ts=1;
    for(ll i = 1;i<=n;i++){
        edl[i-1]=ts;
        if(a[i]>a[i-1]) ts++;
        else{
            uws.push_back(ts);
            ts=1;
        }
    }
    ts=0;
    for(ll i = n-1;i>=0;i--){
        edr[i+1]=ts;
        if(a[i]>a[i+1]) ts++;
        else{
            uws.push_back(ts);
            ts=1;
        }
    }
    edr[0]=ts;
    uws.push_back(ts);
    sort(begin(uws), end(uws));
    ll res=0;
    for(ll i = 0;i<n;i++){
        ll e = max(edl[i], edr[i]), u = min(edl[i], edr[i]);
        ll kt = lower_bound(begin(uws), end(uws), e)-begin(uws);
        if(u>1&&e%2==1&&e==u&&kt==uws.size()-2) res++;
    }
    cout<<res;
}