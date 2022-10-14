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
const int mod = 1e9 + 7, N = 1000001, logN = 20, K = 111, C = 7;

int base[N], pw[N];
vector <int> to[N]; 

int main () {
    owo;
    for (int i = 1; i < N; ++i)
        base[i] = i, pw[i] = 1;
    for (int p = 2; p <= 20; ++p) {
        int now = 2;
        while (true) {
            lli nxt = pow(now, p);
            if (nxt >= N)
                break;
            base[nxt] = now, pw[nxt] = p;
            now++;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        to[base[i]].pb(pw[i]);
    lli ans = 1 + 1ll * (n - 1) * m;
    for (int i = 2; i <= n; ++i) if (!to[i].empty()) {
        int k = to[i].size();
        for (int s = 1; s < 1 << k; ++s) if (__builtin_popcount(s) > 1) {
            lli lcm = 1;
            int mn = 1 << 30;
            for (int j = 0; j < k; ++j) if (s >> j & 1) {
                lcm = lcm * to[i][j] / __gcd(lcm, 1ll * to[i][j]);
                if (lcm > 1ll * m * n) {
                    lcm = 1ll * m * n + 1;
                    break;
                }
                mn = min(mn, to[i][j]);
            }
            if (lcm == m * n + 1)
                continue;
            int x = __builtin_popcount(s);
            ans += (x & 1 ? 1 : -1) * (m / (lcm / mn));
        }
    }
    cout << ans << endl;
}