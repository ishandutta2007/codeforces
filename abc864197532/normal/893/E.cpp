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
const int mod = 1e9 + 7, abc = 864197532, N = 2000007, logN = 17;

int lp[N], mu[N];
lli fac[N], facp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void build() {
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
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (lp[i] == lp[i / lp[i]]) mu[i] = 0;
        else mu[i] = mu[i / lp[i]] * -1;
    }
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
    for (int i = 0; i < N; ++i) facp[i] = modpow(fac[i], mod - 2);
}

lli C(int m, int n) {
    return fac[m] * facp[n] % mod * facp[m - n] % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        vector <pii> f;
        while (x > 1) {
            int p = lp[x], cnt = 0;
            while (x % p == 0) x /= p, cnt++;
            f.eb(p, cnt);
        }
        lli ans = 1;
        for (pii A : f) {
            ans = ans * C(A.Y + y - 1, y - 1) % mod;
        }
        cout << ans * modpow(2, y - 1) % mod << endl;
    }
}