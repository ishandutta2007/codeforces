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
const int mod = 1e9 + 7, N = 500005, logN = 20, M = 1000010;

lli fac[N];
int cnt[M], pre0[M], pre1[M];

int main () {
    owo;
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % mod;
    int n, inv = (mod + 1) >> 1;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x, --x;
        if (x & 1)
            pre1[x >> 1]++;
        else
            pre0[x >> 1]++;
    }
    for (int i = M - 2; ~i; --i) {
        pre1[i] += pre1[i + 1];
        pre0[i] += pre0[i + 1];
    }
    for (int i = 0; i < M; ++i) {
        if (i & 1)
            cnt[i] = pre1[i >> 1];
        else
            cnt[i] = pre0[i >> 1];
    }
    lli ans1 = 0, ans2 = 1, now_idx = 0;
    for (int i = M - 1; ~i; --i) if (cnt[i]) {
        int x = cnt[i];
        ans2 = ans2 * fac[x] % mod;
        ans1 -= 1ll * i * x % mod * ((now_idx + now_idx + x - 1) % mod) % mod * inv % mod;
        if (ans1 < 0)
            ans1 += mod;
        now_idx += x;
    }
    for (int i = 1; i < M; ++i) if (cnt[i]) {
        int x = cnt[i];
        ans2 = ans2 * fac[x] % mod;
        ans1 += 1ll * i * x % mod * ((now_idx + now_idx + x - 1) % mod) % mod * inv % mod;
        if (ans1 >= mod)
            ans1 -= mod;
        now_idx += x;
    }
    cout << ans1 << ' ' << ans2 << endl;
    /*
    (pre[i + 1] - pre[i]) * (i + 1) * (n - i)
    -n * pre[0] - (n + 2) * pre[1] - (n + 4)
    */

}