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
const int mod = 998244353, N = 1 << 20, logN = 19, K = 1 << 9;
 
long long modpow (long long a, int b, int mod) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

struct NTT {
    int mod, rev[N], ninv;
    NTT (int _mod) : mod(_mod) {
        int lg = __lg(N);
        for (int i = 0; i < N; ++i) {
            int t = 0;
            for (int j = 0; j < lg; ++j) {
                if (i >> j & 1) t |= (1 << lg - j - 1);
            }
            rev[i] = t;
        }
        ninv = modpow(N, mod - 2, mod);
    }

    const long long w = modpow(3, (mod - 1) / N, mod);

    void run (vector <long long> &P, bool inv = false) {
        int lg = __lg(N);

        // bit reverse
        for (int i = 0; i < N; ++i) {
            if (i < rev[i]) swap(P[i], P[rev[i]]);
        }

        vector <long long> ws = {inv ? modpow(w, mod - 2, mod) : w};
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
            for (int i = 0; i < N; ++i) {
                P[i] = P[i] * ninv % mod;
            }
        }
    }
    vector <long long> mul (vector <long long> a, vector <long long> b) {
        run(a);
        run(b);
        for (int i = 0; i < N; ++i) a[i] = a[i] * b[i] % mod;
        run(a, true);
        return a;
    }
} ntt(mod);
 
int main () {
    owo;
    int n, x, y;
    cin >> n >> x >> y;
    vector <long long> a(N, 0), b(N, 0);
    for (int i = 0, x; i <= n; ++i) {
        cin >> x;
        a[N / 4 + x]++;
        b[N / 4 - x]++;
    }
    a = ntt.mul(a, b);
    vector <int> is(N, -1);
    for (int i = 1; i <= x; ++i) if (a[N / 2 + i]) {
        is[i * 2 + y * 2] = i * 2 + y * 2;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i)
            is[j] = max(is[j], is[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << is[x] << ' ';
    }
}