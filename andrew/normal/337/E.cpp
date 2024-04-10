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
const ll N = 1e5 + 5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> v[MAXN];
map <ll, ll> mp;

ll a[MAXN], p[MAXN], pr[MAXN], ans = 1e18, stn, n;

void rec(ll x){
    stn++;
    p[stn] = x;
    if(n == stn){
        for(int i = 1; i <= n; i++)pr[i] = 1;
        ll kol = 0;

        for(int i = 1; i <= n; i++){
            if(p[i] == 0)kol++; else{
                if(a[p[i]] / pr[p[i]] < a[i])pr[p[i]] = 1e18;
                else pr[p[i]] *= a[i];
            }
        }

        for(int i = 1; i <= n; i++)if(pr[i] > a[i] || a[i] % pr[i]){
            stn--;
            return;
        }

        ll sc = 0;

        for(int i = 1; i <= n; i++){
            if(p[i] == 0)sc += v[i].size() + (v[i].size() > 1);else{
                if(v[i].size() != 1)sc++;
            }
        }

        if(kol > 1)sc++;
        ans = min(ans, sc);
        stn--;
        return;

    }
    for(int i = 0; i <= stn; i++)rec(i);
    stn--;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        p[i] = i;
        ll x = a[i];
        for(ll j = 2; j * j <= x; j++)if(x % j == 0){
            while(x % j == 0){
                x /= j;
                v[i].p_b(j);
            }
        }
        if(x != 1){
            v[i].p_b(x);
        }
    }

    for(int i = 0; i <= n; i++)if(i != 1)rec(i);
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}