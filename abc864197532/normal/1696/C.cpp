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
const int mod = 998244353, N = 18, logN = 20;

void solve() {
    int n, m, k;
    cin >> n >> m;
    vector <pair <lli, lli>> a(n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].X, a[i].Y = 1, sum += a[i].X;
        while (a[i].X % m == 0) {
            a[i].X /= m, a[i].Y *= m;
        }
    }
    cin >> k;
    vector <int> b(k);
    for (int i = 0; i < k; ++i)
        cin >> b[i], sum -= b[i];
    if (sum) {
        cout << "NO\n";
        return;
    }
    vector <pair <lli, lli>> nxt;
    for (auto [x, v] : a) {
        if (nxt.empty() || nxt.back().X != x)
            nxt.eb(x, v);
        else
            nxt.back().Y += v;
    }
    reverse(all(nxt));
    for (int i = 0, now; i < k; ++i) {
        now = b[i];
        lli x, v; tie(x, v) = nxt.back(); nxt.pop_back();
        if (now <= x * v) {
            if (now % x) {
                cout << "NO\n";
                return;
            }
            int y = now / x;
            v -= y;
            while (y > 1) {
                if (y % m == 0)
                    y /= m;
                else {
                    cout << "NO\n";
                    return;
                }
            }
            if (v)
                nxt.eb(x, v);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}