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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll pref[MAXN][2], nxt[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    s = "+" + s + "-";

    ll ans = 0;

    vector <ll> p(2);

    p[0] = n;
    p[1] = n;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++)pref[i][j] = pref[i - 1][j];
        pref[i][s[i] - 'A']++;
    }

    for(int i = n; i > 0; i--){
        nxt[i] = p[s[i] - 'A'];
        p[s[i] - 'A'] = i;
    }

    for(int i = 1; i < n; i++){
        ll old = ans;
        ans += pref[n][s[i] - 'A'] - pref[i][s[i] - 'A'];
        ans += max(0ll, pref[n][1 - s[i] + 'A'] - pref[nxt[i]][1 - s[i] + 'A'] - ((pref[nxt[i]][1 - s[i] + 'A'] - pref[i][1 - s[i] + 'A']) == 0));
    }
    cout << ans << "\n";
    return 0;
}