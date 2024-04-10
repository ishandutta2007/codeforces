/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
const int mod = 998244353, N = 200001, logN = 19, K = 1 << 9;

long long modpow (long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void run (vector <long long> &P, bool inv = false) {
    int N = P.size();
    const long long w = modpow(3, (mod - 1) / N);
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

void mul (vector <long long> &a, vector <long long> b) {
    int N = 1 << __lg(a.size() + b.size() - 1) + 1;
    a.resize(N), b.resize(N);
    run(a), run(b);
    for (int i = 0; i < N; ++i) a[i] = a[i] * b[i] % mod;
    run(a, true);
}

lli fac[N], facp[N];

lli C(int n, int m) {
    if (n < m || n < 0 || m < 0)
        return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = modpow(fac[i], mod - 2);
    }
    int n;
    cin >> n;
    vector <lli> cur = {1};
    int now = 0;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        vector <lli> nxt;
        for (int i = y - now; i <= x + now; ++i) {
            nxt.pb(C(x + y, i));
        }
        mul(cur, nxt);
        for (int i = 0; i <= now + x - y; ++i)
            cur[i] = cur[now + i];
        now += x - y;
        cur.resize(now + 1);
    }
    cout << accumulate(all(cur), 0ll) % mod << endl;
}