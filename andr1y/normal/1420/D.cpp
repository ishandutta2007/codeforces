#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 3e5+228;
const ll M = 998244353;
ll l[N], r[N];
yree sz;
ll st[N+N], ed[N+N];
ll f[N], of[N];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for(ll i = 0;i<n;i++){
        cin >> l[i] >> r[i];
        sz.insert(l[i]);
        sz.insert(r[i]);
    }
    f[0]=1;
    for(ll i = 1;i<N;i++){
        f[i] = (f[i-1]*i) %M;
    }
    of[N-1] = 329051142;
    for(ll i = N-2;i>=0;i--){
        of[i] = (of[i+1]*(i+1))%M;
    }
    //for(ll i = 1;i<N;i++) assert((f[i]*of[i])%M==1);
    if(k==1){
        cout<<n;
        return 0;
    }
    for(ll i =0;i<n;i++){
        l[i] = sz.order_of_key(l[i]);
        r[i] = sz.order_of_key(r[i]);
        st[l[i]]++;
        ed[r[i]]++;
    }
    ll k2=0;
    ll res=0;
    for(ll i = 0;i<sz.size();i++){
        k2+=st[i];
        for(ll jj = 0;jj<ed[i];jj++){
            --k2;
            if(k2>k-2){
                ll v = (f[k2]*of[k2-k+1])%M;
                v = (v*of[k-1]) %M;
                res = (res+v) %M;
            }
        }
    }
    cout<<res;
}