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
const int mod = 1e9 + 7, N = 200000, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        map <string, pii> m1[2];
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j + 2 <= m; ++j) {
                string nxt;
                nxt.pb(s[j]), nxt.pb(s[j + 1]);
                m1[0][nxt] = mp(i, j);
            }
            for (int j = 0; j + 3 <= m; ++j) {
                string nxt;
                nxt.pb(s[j]), nxt.pb(s[j + 1]), nxt.pb(s[j + 2]);
                m1[1][nxt] = mp(i, j);
            }
        }
        cin >> s;
        vector <bool> dp(m + 1, false);
        vector <pair <int, pii>> pt(m + 1);
        dp[0] = true;
        for (int i = 2; i <= m; ++i) {
            if (i >= 2 && dp[i - 2]) {
                string nxt;
                nxt.pb(s[i - 2]), nxt.pb(s[i - 1]);
                if (m1[0].count(nxt)) {
                    dp[i] = true;
                    pt[i] = mp(i - 2, m1[0][nxt]);
                }
            }
            if (i >= 3 && dp[i - 3]) {
                string nxt;
                nxt.pb(s[i - 3]), nxt.pb(s[i - 2]), nxt.pb(s[i - 1]);
                if (m1[1].count(nxt)) {
                    dp[i] = true;
                    pt[i] = mp(i - 3, m1[1][nxt]);
                }
            }
        }
        if (dp[m]) {
            vector <pair <pii, int>> ans;
            int now = m;
            while (now > 0) {
                int p = pt[now].X;
                ans.pb(mp(mp(pt[now].Y.Y + 1, pt[now].Y.Y + now - p), pt[now].Y.X + 1));
                now = p;
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            for (auto A : ans)
                cout << A.X.X << ' ' << A.X.Y << ' ' << A.Y << endl;
        } else {
            cout << -1 << endl;
        }
    }
}