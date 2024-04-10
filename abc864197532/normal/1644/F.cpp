#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200005, logN = 18, K = 1 << 8, G = 3;

int lp[N], mu[N];

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
}

long long modpow (long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

struct NTT {
    NTT () {}

    void run (vector <long long> &P, bool inv = false) {
        int N = P.size();
        const long long w = modpow(G, (mod - 1) / N);
        int lg = __lg(N);
        vector <int> rev(N);

        // bit reverse
        for (int i = 1; i < N; ++i) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
            if (i < rev[i])
                swap(P[i], P[rev[i]]);
        }

        vector <long long> ws = {inv ? modpow(w, mod - 2) : w};
        for (int i = 1; i < lg; ++i) ws.push_back(ws.back() * ws.back() % mod);
        reverse(ws.begin(), ws.end());

        for (int i = 0; i < lg; ++i) {
            for (int k = 0; k < N; k += (2 << i)) {
                long long base = 1;
                for (int j = k; j < k + (1 << i); ++j, base = base * ws[i] % mod) {
                    long long t = base * P[j + (1 << i)] % mod, u = P[j];
                    P[j] = u + t;
                    if (P[j] >= mod) P[j] -= mod;
                    P[j + (1 << i)] = u - t;
                    if (P[j + (1 << i)] < 0) P[j + (1 << i)] += mod;
                }
            }
        }

        if (inv) {
            long long ninv = modpow(N, mod - 2);
            for (int i = 0; i < N; ++i) {
                P[i] = P[i] * ninv % mod;
            }
        }
    }

    vector <long long> mul (vector <long long> a, vector <long long> b) {
        int m = a.size() + b.size() - 1;
        int N = 1 << __lg(m) + 1;
        a.resize(N), b.resize(N);
        run(a), run(b);
        for (int i = 0; i < N; ++i) a[i] = a[i] * b[i] % mod;
        run(a, true);
        a.resize(m);
        return a;
    }
} ntt;

lli fac[N], facp[N];

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = modpow(fac[i], mod - 2);
    }
    build();
    int n, k;
    cin >> n >> k;
    if (n == 1 || k == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector <vector <long long>> dp(n + 1);
    vector <bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i)
        vis[(n + i - 1) / i] = true;
    for (int x = 1; x <= n; ++x) if (vis[x]) {
        vector <long long> a(x + 1), b(x + 1);
        for (int i = 0; i <= x; ++i) {
            a[i] = modpow(i, x) * facp[i] % mod;
            b[i] = facp[i];
            if (i & 1)
                b[i] = mod - b[i];
        }
        vector <long long> c = ntt.mul(a, b);
        dp[x] = c;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int len = (n + i - 1) / i, x = mod - 1;
        for (int j = 0; j <= min(k, len); ++j) {
            x += dp[len][j];
            if (x >= mod)
                x -= mod;
        }
        if (mu[i] == 1) {
            ans += x;
            if (ans >= mod)
                ans -= mod;
        } else if (mu[i] == -1) {
            ans -= x;
            if (ans < 0)
                ans += mod;
        }
    }
    cout << ans << endl;
}