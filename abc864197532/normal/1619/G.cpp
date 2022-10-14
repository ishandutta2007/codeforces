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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1100005, logN = 18;

struct bomb {
    int x, y, t, id;
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <bomb> a(n);
        vector <vector <int>> adj(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].x >> a[i].y >> a[i].t, a[i].id = i;
        sort(all(a), [&](bomb i, bomb j) {
            if (i.x == j.x)
                return i.y < j.y;
            return i.x < j.x;
        });
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i].x == a[j].x)
                j++;
            for (int t = i + 1; t < j; ++t) {
                if (a[t].y - a[t - 1].y <= k) {
                    adj[a[t - 1].id].pb(a[t].id);
                    adj[a[t].id].pb(a[t - 1].id);
                }
            }
        }
        sort(all(a), [&](bomb i, bomb j) {
            if (i.y == j.y)
                return i.x < j.x;
            return i.y < j.y;
        });
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i].y == a[j].y)
                j++;
            for (int t = i + 1; t < j; ++t) {
                if (a[t].x - a[t - 1].x <= k) {
                    adj[a[t - 1].id].pb(a[t].id);
                    adj[a[t].id].pb(a[t - 1].id);
                }
            }
        }
        vector <bool> vis;
        function<void(int)> dfs = [&](int v) {
            vis[v] = true;
            for (int u : adj[v]) if (!vis[u])
                dfs(u);
        };
        sort(all(a), [&](bomb i, bomb j) {
            return i.id < j.id;
        });
        int l = -1, r = n + 1;
        while (r - l > 1) {
            vis.assign(n, false);
            int m = l + r >> 1;
            for (int i = 0; i < n; ++i) if (a[i].t <= m && !vis[i])
                dfs(i);
            int cnt = 0;
            for (int i = 0; i < n; ++i) if (a[i].t > m && !vis[i]) {
                dfs(i);
                cnt++;
            }
            if (cnt <= m + 1)
                r = m;
            else
                l = m;
        }
        cout << r << endl;
    }
}