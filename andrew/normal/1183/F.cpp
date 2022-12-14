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
const ll N = 2e5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> v[MAXN];

bool f[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i)v[j].p_b(i);
    }

    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n + 1);

        set <ll> s;
        vector <ll> d, ct;

        for(int i = 1; i <= n; i++)cin >> a[i];
        sort(a.begin() + 1, a.end());
        ll ans = a[n];
        for(int i = 1; i < n; i++)if(a[n] % a[i]){
            if(d.empty() || d.back() != a[i])d.p_b(a[i]);
        }
        ll uk = 0;
        for(auto i : d){
            ll t = uk;
            while(t >= 0 && i % d[t] == 0)t--;
            ll sc = a[n] + i;
            if(t >= 0)sc += d[t];
            ans = max(ans, sc);
            uk++;
        }

        for(int i = 1; i <= n; i++)f[a[i]] = 1;

        for(int i = 1; i <= n; i++)if(a[i] % 30 == 0){
            if(f[a[i] / 2] && f[a[i] / 3] && f[a[i] / 5])ans = max(ans, a[i] / 2 + a[i] / 3 + a[i] / 5);

        }

        for(int i = 1; i <= n; i++)f[a[i]] = 0;

        s.clear();
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}