#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ld inf = 1e18;
ll N;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector <ll> a(n);
    for(auto &i : a)cin >> i;

    vector <ll> cnt(35);

    pll ans = {-1, -1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++)if((a[i] & pw(j)))cnt[j]++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++)if((a[i] & pw(j)))cnt[j]--;
        ll sc = 0;
        for(int j = 0; j < 32; j++)if((a[i] & pw(j)) && cnt[j] == 0)sc |= pw(j);
        ans = max(ans, {sc, i});
        for(int j = 0; j < 32; j++)if((a[i] & pw(j)))cnt[j]++;
    }

    swap(a[0], a[ans.se]);

    for(auto i : a)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}