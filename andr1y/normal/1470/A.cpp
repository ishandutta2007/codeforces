// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll k[N], c[N], k2[N];
bool ban[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            cin >> k[i];
            ban[i]=0;
            k[i]--;
            k2[i]=k[i];
        }
        for(ll i = 0;i<m;i++){
            cin >> c[i];
        }
        ll res=0;
        for(ll i = 0;i<n;i++) res+=c[k[i]];
        ll mr=res;
        sort(k2, k2+n, greater<ll>());
        ll tsp=0, tss=0;
        for(ll i = 0;i<m&&i<n;i++){
            if(k2[i]<i) break;
            tsp+=c[i];
            tss+=c[k2[i]];
            mr=min(mr, res-tss+tsp);
        }
        cout<<mr<<'\n';
    }
}