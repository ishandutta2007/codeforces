#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll dp[N + 5][2];
 
vector <ll> gold[N + 5];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    set <ll> List;
 
    vector <pll> a(k);
 
    for(int i = 0; i < k; i++){
        cin >> a[i].fi >> a[i].se;
        List.insert(a[i].fi);
        gold[a[i].fi].p_b(a[i].se);
    }
 
    for(int i = 1; i <= n; i++)sort(all(gold[i]));
 
    vector <ll> b(q);
 
    for(int i = 0; i < q; i++)cin >> b[i];
 
 
    sort(all(b));
 
    ll Ft = *List.begin();
 
    if(Ft == 1){
        ll pos = 1;
        dp[Ft][1] = abs(pos - gold[1].back());
        dp[Ft][0] = abs(pos - gold[1].back()) + gold[1].back() - gold[1][0];
    }else{
        ll pos = *lower_bound(all(b), 1);
        ll sc = 0;
        sc += pos - 1;
        sc += Ft - 1;
        dp[Ft][1] = abs(pos - gold[Ft][0]) + abs(gold[Ft][0] - gold[Ft].back()) + sc;
        dp[Ft][0] = abs(pos - gold[Ft].back()) + abs(gold[Ft][0] - gold[Ft].back()) + sc;
    }
 
    ll last = Ft;
 
    vector <ll> :: iterator it;
 
    for(auto i : List){
        if(i == Ft)continue;
        dp[i][0] = dp[i][1] = 1e18;
 
        it = lower_bound(all(b), gold[last][0]);
 
        if(it != b.end()){
            ll pos = *it;
            ll sc = dp[last][0];
            sc += abs(pos - gold[last][0]);
            sc += i - last;
            dp[i][1] = min(dp[i][1], abs(pos - gold[i][0]) + abs(gold[i][0] - gold[i].back()) + sc);
            dp[i][0] = min(dp[i][0], abs(pos - gold[i].back()) + abs(gold[i][0] - gold[i].back()) + sc);
        }
 
        it = upper_bound(all(b), gold[last][0]);
 
        if(it != b.begin()){
            ll pos = *--it;
            ll sc = dp[last][0];
            sc += abs(pos - gold[last][0]);
            sc += i - last;
            dp[i][1] = min(dp[i][1], abs(pos - gold[i][0]) + abs(gold[i][0] - gold[i].back()) + sc);
            dp[i][0] = min(dp[i][0], abs(pos - gold[i].back()) + abs(gold[i][0] - gold[i].back()) + sc);
        }
 
        it = lower_bound(all(b), gold[last].back());
 
        if(it != b.end()){
            ll pos = *it;
            ll sc = dp[last][1];
            sc += abs(pos - gold[last].back());
            sc += i - last;
            dp[i][1] = min(dp[i][1], abs(pos - gold[i][0]) + abs(gold[i][0] - gold[i].back()) + sc);
            dp[i][0] = min(dp[i][0], abs(pos - gold[i].back()) + abs(gold[i][0] - gold[i].back()) + sc);
        }
 
        it = upper_bound(all(b), gold[last].back());
 
        if(it != b.begin()){
            ll pos = *--it;
            ll sc = dp[last][1];
            sc += abs(pos - gold[last].back());
            sc += i - last;
            dp[i][1] = min(dp[i][1], abs(pos - gold[i][0]) + abs(gold[i][0] - gold[i].back()) + sc);
            dp[i][0] = min(dp[i][0], abs(pos - gold[i].back()) + abs(gold[i][0] - gold[i].back()) + sc);
        }
        last = i;
    }
 
    cout << min(dp[last][0], dp[last][1]) << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}