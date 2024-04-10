#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;
ll a[N];
map<ll, ll> cnt;
map<ll, vector<ll>> cell;
map<pll, map<ll, vector<ll>>> bans;
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n>> m;
        cnt.clear();
        cell.clear();
        bans.clear();
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a, a+n);
        for(auto i : cnt){
            cell[i.y].push_back(i.x);
        }
        for(ll i = 0;i<m;i++){
            ll a, b;
            cin >> a >> b;
            ll ca = cnt[a], cb = cnt[b];
            if(ca > cb) swap(ca, cb), swap(a, b);
            bans[{ca, cb}][a].push_back(b);
            bans[{ca, cb}][b].push_back(a);
        }
        vector<ll> cnts;
        ll res=0;
        for(auto i : cell) cnts.push_back(i.x);
        for(ll i = 0;i<(ll)cnts.size();i++){
            vector<ll> &ob = cell[cnts[i]];
            for(ll j = i;j<(ll)cnts.size();j++){
                ll kf = cnts[i]+cnts[j];
                vector<ll> &oj = cell[cnts[j]];
                map<ll, vector<ll>> &bob = bans[{cnts[i], cnts[j]}];
                for(ll v = 0;v<(ll)ob.size();v++){
                    ll pr = oj.size()-1;
                    vector<ll> &tb = bob[ob[v]];
                    tb.push_back(ob[v]);
                    sort(tb.begin(), tb.end(), greater<ll>());
                    for(auto u : tb){
                        if(oj[pr] < u) continue;
                        if(oj[pr] == u) --pr;
                        else break;
                        if(pr<0) break;
                    }
                    if(pr!=-1) res=max(res, kf * (ob[v] + oj[pr]));
                }
            }
        }
        cout<<res<<'\n';
    }
}