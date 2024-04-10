#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txst", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int P = 1e9 + 7;

const int MAXN = 5000500;
int a[MAXN], t[MAXN], res[MAXN], nxt[MAXN];
ll rem[MAXN];

const int MAXM = 200200;
int p[MAXN], k[MAXN], b[MAXN], w[MAXN];

int seed = 0;
int base = 0;

int rnd() {
    int ret = seed;
    seed = (ll(seed) * base + 233) % 1000000007;
    return ret;
}


void solve() {  
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        cin >> p[i] >> k[i] >> b[i] >> w[i];
    }


    p[0] = 0;
    for (int i = 1; i <= m; ++i) {
        seed = b[i];
        base = w[i];
        for (int j = p[i - 1]; j < p[i]; ++j) {
            t[j] = rnd() & 1;
            a[j] = (rnd() % k[i]) + 1;
        } 
    }
    if (t[0]) {
        for (int i = 0; i < n; ++i) {
            t[i] ^= 1;
        }
    }

    array<ll, 2> sum = {0, 0};
    for (int i = 0; i < n; ++i) {
        sum[t[i]] += a[i];
    }

    auto f = [&]() {
        ll ans = 1;
        for (ll i = 0; i < n; ++i) {
            ll cur = ((res[i] ^ ((i + 1) * (i + 1))) + 1) % P;
            ans = ans * cur % P;
        }
        return ans;
    };

    int st = 0;
    if (sum[0] <= sum[1]) {
        for (int i = 0; i < n; ++i) {
            if (t[i]) {
                st = i;
                break;
            }
        }

        if (st == 0) {
            cout << f() << endl;
            return;
        }

        --a[0];
        ++res[0];
        for (int i = 0; i < n; ++i) {
            t[i] ^= 1;
        }
    }

    --a[st];
    ++res[st];

    int pos = -1;
    for (int j = 2 * n - 1; j >= 0; --j) {
        int i = (j >= n ? j - n : j);
        nxt[i] = pos;
        if (!t[i]) {
            pos = i;
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << nxt[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; ++i) {
        if (t[i]) {
            res[i] += a[i];
            rem[nxt[i]] += a[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (t[i]) {
            continue;
        }
        int j = i;

        while (true) {
            ll x = min<ll>(a[j], rem[j]);
            a[j] -= x;
            res[j] += x;
            rem[j] -= x;
            if (rem[j] > 0) {
                rem[nxt[j]] += rem[j];
                rem[j] = 0;
                j = nxt[j];
            }  else {
                nxt[i] = (i == j ? nxt[i] : j);
                break;
            }
        }
    }

    cout << f() << endl;
}