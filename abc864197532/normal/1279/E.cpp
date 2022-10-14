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
const int mod = 998244353, N = 55;
const ll INF = 1ll << 60;

ll val[N], dp[N];

ll mul(ll a, ll b) {
    if (!b)
        return 0;
    if (a > INF / b)
        return INF;
    return a * b;
}

vector <int> find_perm(int n, ll k) {
    if (n == 1) {
        return {0};
    }
    if (n == 2) {
        return {1, 0};
    }
    if (n == 3) {
        return {2, 0, 1};
    }
    vector <int> ans;
    ans.pb(n - 1);
    vector <bool> vis(n, false);
    vis[n - 1] = true;
    int remain = n - 1;
    while (remain > 3) {
        int now = -1;
        while (true) {
            now++;
            if (vis[now] || now == n - remain)
                continue;
            int cur = now;
            bool fail = false;
            while (true) {
                if (cur == ans.size()) {
                    fail = true;
                    break;
                }
                if (cur < ans.size())
                    cur = ans[cur];
                else
                    break;
            }
            if (fail)
                continue;
            if (k >= val[remain]) {
                k -= val[remain];
            } else {
                break;
            }
        }
        ans.pb(now), vis[now] = true, remain--;
    }
    vector <int> ord;
    for (int i = 0; i < n; ++i) if (!vis[i])
        ord.pb(i);
    do {
        vector <int> res = ans;
        for (int i : ord)
            res.pb(i);
        int now = 0;
        vector <bool> vis(n, false);
        while (!vis[now])
            vis[now] = true, now = res[now];
        if (count(all(vis), true) == n) {
            if (!k)
                return res;
            k--;
        }
    } while (next_permutation(all(ord)));
    assert(false);
}

vector <int> find_perm_bf(int n, ll k) {
    vector <int> ans(n);
    ans[0] = n - 1;
    iota(1 + all(ans), 0);
    do {
        int now = 0;
        vector <bool> vis(n, false);
        while (!vis[now])
            vis[now] = true, now = ans[now];
        if (count(all(vis), true) == n) {
            if (!k)
                return ans;
            k--;
        }
    } while (next_permutation(all(ans)));
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    if (k > dp[n]) {
        cout << "-1\n";
        return;
    }
    k--;
    vector <int> ans;
    int now = 0;
    while (now < n) {
        int len = 1;
        while (true) {
            ll way = mul(val[len], dp[n - now - len]);
            if (way <= k) {
                k -= way;
                len++;
            } else {
                break;
            }
        }
        ll round = k / dp[n - now - len];
        k -= mul(round, dp[n - now - len]);
        vector <int> res = find_perm(len, round);
        for (int i : res)
            ans.pb(now + i);
        now += len;
    }
    for (int &i : ans)
        i++;
    printv(all(ans));
}

void build() {
    val[1] = val[2] = val[3] = 1;
    for (int i = 4; i < N; ++i) {
        val[i] = mul(val[i - 1], i - 2);
    }
    dp[0] = 1;
    for (int n = 1; n < N; ++n) {
        for (int i = 1; i <= n; ++i) {
            dp[n] += mul(dp[n - i], val[i]);
            if (dp[n] > INF)
                dp[n] = INF;
        }
    }
}

int main () {
    owo;
    build();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}