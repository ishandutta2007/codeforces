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
const int mod = 998244353, N = 1 << 18, logN = 18, G = 3;

int main () {
    owo;
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector <pii> cost[2];
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y, --x;
        cost[x].eb(y, i);
    }
    sort(all(cost[0])), sort(all(cost[1]));
    vector <pii> ans;
    int pt[2];
    auto ask = [&](int day) {
        int mn1 = 1 << 30, mn2 = 1 << 30;
        for (int i = 0; i < day; ++i) {
            mn1 = min(mn1, a[i]), mn2 = min(mn2, b[i]);
        }
        for (int i = 0; i < day; ++i) {
            if (mn1 == a[i])
                pt[0] = i;
            if (mn2 == b[i])
                pt[1] = i;
        }
        ans.clear();
        lli remain = s;
        for (int i = 0, j = 0; i + j < k; ) {
            lli now1 = 1ll << 60, now2 = 1ll << 60;
            if (i < cost[0].size())
                now1 = min(now1, 1ll * mn1 * cost[0][i].X);
            if (j < cost[1].size())
                now2 = min(now2, 1ll * mn2 * cost[1][j].X);
            if (now1 > now2) {
                if (remain >= now2) {
                    remain -= now2;
                    ans.eb(cost[1][j++].Y, 1);
                } else {
                    return false;
                }
            } else {
                if (remain >= now1) {
                    remain -= now1;
                    ans.eb(cost[0][i++].Y, 0);
                } else {
                    return false;
                }
            }
        }
        return true;
    };
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (ask(m))
            r = m;
        else
            l = m;
    }
    if (r == n + 1) {
        cout << "-1\n";
        return 0;
    }
    ask(r);
    cout << r << '\n';
    for (auto [x, y] : ans) {
        cout << x + 1 << ' ' << pt[y] + 1 << '\n';
    }
}