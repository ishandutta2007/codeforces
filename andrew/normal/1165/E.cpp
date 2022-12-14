#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


const ll MOD = 998244353;

ll f(ll x){
    return x * (x + 1) / 2;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];

    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());

    vector <ll> c(n + 1);

    for(ll i = 1; i <= n; i++){
        c[i] = (i) * (n - i + 1) * a[i];
    }
    sort(c.begin() + 1, c.end());
    ll sc = 0, s = 0;

    ll kol = 0, ans = 0;

    for(int i = n; i > 0; i--){
        ll val = ((c[i] % MOD) * b[i]) % MOD;
        (ans += val) %= MOD;
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}