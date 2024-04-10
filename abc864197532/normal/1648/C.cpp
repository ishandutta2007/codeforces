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
const int mod = 998244353, N = 200087, logN = 20, K = 111, C = 7;

lli fac[N], facp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

/*
 (a1 + a2 + a3)!/a1!/a2!/a3!
 (sum - 1)!/a1!/a2!/a3!*(a1+a2+a3+...+ak)
 */

struct BIT {
    long long bit[N];
    BIT ()  {
        for (int i = 0; i < N; ++i) bit[i] = 0;
    }
    void add (int p, long long a) {
        for (int i = p; i < N; i += (i & -i)) bit[i] += a;
    }
    long long query (int p) {
        long long all = 0;
        for (int i = p; i > 0; i -= (i & -i)) all += bit[i];
        return all;
    }
    int kth (long long k) {
        int ans = 0;
        for (int i = 1 << __lg(N); i > 0; i >>= 1) {
            if (ans + i < N and bit[ans + i] < k) k -= bit[ans += i];
        }
        return ans + 1;
    }
} bit;

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = modpow(fac[i], mod - 2);
    }
    int n, m;
    cin >> n >> m;
    vector <int> s(n), t(m);
    vector <int> cnt(N, 0);
    for (int i = 0; i < n; ++i)
        cin >> s[i], cnt[s[i]]++, bit.add(s[i], 1);
    for (int i = 0; i < m; ++i)
        cin >> t[i];
    lli now = fac[n];
    for (int i = 1; i < N; ++i)
        now = now * facp[cnt[i]] % mod;
    lli ans = 0;
    for (int i = 0; i < m; ++i) {
        if (i >= n) {
            (ans += 1) %= mod;
            break;
        }
        int x = t[i];
        int c = bit.query(x - 1);
        (ans += now * modpow(n - i, mod - 2) % mod * c) %= mod;
        now = now * fac[cnt[x]] % mod;
        bit.add(x, -1), cnt[x]--;
        if (cnt[x] < 0)
            break;
        now = now * facp[cnt[x]] % mod * modpow(n - i, mod - 2) % mod;
    }
    cout << ans << endl;
}