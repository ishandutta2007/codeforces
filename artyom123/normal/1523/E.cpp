 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
mt19937 gen(time(0));

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    else return (((now * now) % mod) * n) % mod;
}
vector<ll> fact, invfact;

ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invfact[k]) % mod) * invfact[n - k]) % mod;
}

ll cnt_count(ll n, ll p, ll k) {
    return C(n - (p - 1) * (k - 1), p);
}

ll cnt_pr(ll n, ll p) {
    return my_pow(C(n, p), mod - 2);
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    fact.resize(MAXN);
    invfact.resize(MAXN);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = my_pow(fact[i], mod - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        int n, k;
        cin >> n >> k;
        for (int p = 1; p <= n; p++) {
            ans += cnt_count(n, p, k) * cnt_pr(n, p);
            ans %= mod;
        }
        cout << (ans + 1) % mod << "\n";
    }
    return 0;
}