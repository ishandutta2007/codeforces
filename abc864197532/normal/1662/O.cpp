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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        vv <bool> cir(21, 360, false); // theta from i to i + 1
        vv <bool> line(21, 360, false); // radius from i to i + 1
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if (c == 'C') {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                for (int i = t1; i != t2; i = (i + 1) % 360) {
                    cir[r][i] = true;
                }
            } else {
                int r1, r2, te;
                cin >> r1 >> r2 >> te;
                for (int i = r1; i < r2; ++i) {
                    line[i][te] = true;
                }
            }
        }
        vv <bool> vis(21, 360, false); // in theta range [i, i + 1)
        queue <pii> q;
        for (int i = 0; i < 360; ++i)
            q.emplace(20, i), vis[20][i] = true;
        bool ans = false;
        while (!q.empty()) {
            int r, te; tie(r, te) = q.front(); q.pop();
            if (r == 0) {
                ans = true;
                break;
            }
            if (!line[r][(te + 1) % 360] && !vis[r][(te + 1) % 360]) {
                vis[r][(te + 1) % 360] = true;
                q.emplace(r, (te + 1) % 360);
            }
            if (!line[r][te] && !vis[r][(te + 359) % 360]) {
                vis[r][(te + 359) % 360] = true;
                q.emplace(r, (te + 359) % 360);
            }
            if (!cir[r][te] && !vis[r - 1][te]) {
                vis[r - 1][te] = true;
                q.emplace(r - 1, te);
            }
            if (r < 20 && !cir[r + 1][te] && !vis[r + 1][te]) {
                vis[r + 1][te] = true;
                q.emplace(r + 1, te);
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}