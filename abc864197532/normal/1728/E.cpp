#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 998244353, N = 300001, C = 550;

ll pre[C][C];

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    vector <ll> dp(n + 1); // i * a
    dp[0] = accumulate(all(a), 0ll);
    priority_queue <int> pq;
    for (int i = 0; i < n; ++i)
        pq.push(b[i] - a[i]);
    for (int i = 1; i <= n; ++i) {
        int x = pq.top(); pq.pop();
        dp[i] = dp[i - 1] + x;
    }
    for (int x = 1; x < C; ++x) {
        for (int r = 0; r < x; ++r) {
            for (int i = r; i <= n; i += x) {
                pre[x][r] = max(pre[x][r], dp[i]);
            }
        }
    }
    int q; cin >> q;
    // ax + by = n
    // a = (n - by) / x
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll lcm = 1ll * x * y / __gcd(x, y);
        if (x < C) {
            int a = -1, b = -1;
            for (int i = 0; i < x && i * y <= n; ++i) if ((n - i * y) % x == 0) {
                a = (n - i * y) / x, b = i;
                break;
            }
            if (a == -1)
                cout << "-1\n";
            else if (lcm < C) {
                cout << pre[lcm][b * y] << '\n';
            } else {
                ll ans = -1;
                // ax + by = n
                for (int i = b * y; i <= n; i += lcm)
                    ans = max(ans, dp[i]);
                cout << ans << '\n';
            }
        } else {
            ll ans = -1;
            for (int i = 0; i * x <= n; ++i) if ((n - i * x) % y == 0) {
                ans = max(ans, dp[n - i * x]);
            }
            cout << ans << '\n';
        }
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}