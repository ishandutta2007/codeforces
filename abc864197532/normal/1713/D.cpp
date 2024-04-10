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
const int mod = 1e9 + 7, N = 333333;

int query(int x, int y) {
    cout << "? " << ++x << ' ' << ++y << endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector <int> alive;
    for (int i = 0; i < 1 << n; ++i) {
        alive.pb(i);
    }
    while (alive.size() > 1) {
        vector <int> nxt;
        if (alive.size() == 2) {
            if (query(alive[0], alive[1]) == 1) {
                nxt.pb(alive[0]);
            } else {
                nxt.pb(alive[1]);
            }
        } else {
            for (int i = 0; i < alive.size(); i += 4) {
                int a = alive[i], b = alive[i + 1], c = alive[i + 2], d = alive[i + 3];
                int x = query(a, c);
                if (x == 0) {
                    if (query(b, d) == 1) {
                        nxt.pb(b);
                    } else {
                        nxt.pb(d);
                    }
                } else if (x == 1) {
                    if (query(a, d) == 1) {
                        nxt.pb(a);
                    } else {
                        nxt.pb(d);
                    }
                } else {
                    if (query(b, c) == 1) {
                        nxt.pb(b);
                    } else {
                        nxt.pb(c);
                    }
                }
            }
        }
        alive = nxt;
    }
    cout << "! " << alive[0] + 1 << endl;
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}