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
const int mod = 998244353, N = 52, logN = 18, G = 3;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int x = 0; x <= a; ++x) {
        if (c - x == b - (a - x) && c - x >= 0) {
            int V = a + 1 + c - x;
            if (V <= n) {
                cout << "YES\n";
                vector <int> line = {1};
                set <int> vis;
                int now = 4;
                for (int t = 0; t < a - 1; ++t) {
                    line.pb(now++);
                }
                line.pb(2);
                if (c - x == 0) {
                    int del = line[x];
                    for (int &i : line) if (i > n)
                        i = del;
                    line[x] = 3;
                    for (int i = 1; i < line.size(); ++i) {
                        cout << line[i - 1] << ' ' << line[i] << '\n', vis.insert(line[i - 1]), vis.insert(line[i]);
                    }
                } else {
                    for (int i = 1; i < line.size(); ++i) {
                        cout << line[i - 1] << ' ' << line[i] << '\n', vis.insert(line[i - 1]), vis.insert(line[i]);
                    }
                    int st = line[x];
                    for (int i = 0; i < c - x - 1; ++i) {
                        cout << st << ' ' << now << '\n', vis.insert(st), vis.insert(now);
                        st = now++;
                    }
                    cout << st << ' ' << 3 << '\n', vis.insert(3);
                }
                assert(vis.size() == V);
                for (int i = 1; i <= n; ++i) if (!vis.count(i))
                    cout << 1 << ' ' << i << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}