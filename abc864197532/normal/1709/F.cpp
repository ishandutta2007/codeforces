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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200005, logN = 18, G = 3;

long long modpow (long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

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
    for (int i = 1; i < lg; ++i) 
        ws.push_back(ws.back() * ws.back() % mod);
    reverse(ws.begin(), ws.end());

    for (int i = 0; i < lg; ++i) {
        for (int k = 0; k < N; k += (2 << i)) {
            long long base = 1;
            for (int j = k; j < k + (1 << i); ++j, base = base * ws[i] % mod) {
                long long t = base * P[j + (1 << i)] % mod, u = P[j];
                P[j] = u + t;
                if (P[j] >= mod) 
                    P[j] -= mod;
                P[j + (1 << i)] = u - t;
                if (P[j + (1 << i)] < 0) 
                    P[j + (1 << i)] += mod;
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

vector <long long> sq (vector <long long> a) {
    int m = a.size() + a.size() - 1;
    int N = 1 << __lg(m) + 1;
    a.resize(N);
    run(a);
    for (int i = 0; i < N; ++i) 
        a[i] = a[i] * a[i] % mod;
    run(a, true);
    a.resize(m);
    return a;
}

int main () {
    owo;
    /*
     dp[i] = dp[a] * dp[b] * (k - i + 1)[a + b = i] + dp[a] * dp[b] [a + b > i]
     */
    int n, k, f;
    cin >> n >> k >> f;
    vector <lli> cur(k + 1, 0);
    for (int i = 0; i <= k; ++i)
        cur[i] = 1;
    for (int _ = 1; _ < n; ++_) {
        vector <lli> combine = sq(cur);
        vector <lli> nxt(k + 1, 0);
        lli presum = 0;
        for (int i = k + k; ~i; --i) {
            if (i <= k)
                nxt[i] = (combine[i] * (k - i + 1) + presum) % mod;
            presum += combine[i];
            if (presum >= mod)
                presum -= mod;
        }
        cur = nxt;
    }
    lli ans = 0;
    for (int i = 0; i <= f; ++i) if (i <= k && f - i <= k) {
        (ans += cur[i] * cur[f - i]) %= mod;
    }
    cout << ans << '\n';
}