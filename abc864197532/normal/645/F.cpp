#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 3e6;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int lp[N], phi[N];
vector <int> f[N];
lli C[N], cur[N], ans = 0;

void build(int k) {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    phi[1] = 1;
    for (int i = 2; i < N; ++i) {
        int j = i, tmp = 1;
        while (j % lp[i] == 0) j /= lp[i], tmp *= lp[i];
        if (j != 1) phi[i] = phi[j] * phi[tmp];
        else phi[i] = i / lp[i] * (lp[i] - 1);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            f[j].pb(i);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i <= k) C[i] = (i == k);
        else C[i] = C[i - 1] * i % mod * modpow(i - k, mod - 2) % mod;
    }
}

void add(int v) {
    for (int j : f[v]) {
        ans = (ans - C[cur[j]] * phi[j]) % mod;
        cur[j]++;
        ans = (ans + C[cur[j]] * phi[j]) % mod;
    }
    if (ans < 0) ans += mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp, q;
    cin >> n >> k >> q;
    build(k);
    for (int i = 0; i < n; ++i) cin >> tmp, add(tmp);
    while (q--) {
        cin >> tmp;
        add(tmp);
        cout << ans << '\n';
    }
}