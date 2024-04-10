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
const int mod = 998244353, N = 400100, logN = 20, M = 6e6;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> cnt(a[n - 1] + 1, 0);
    for (int i : a)
        cnt[i]++;
    vector <pii> now;
    for (int i = 0; i <= a[n - 1]; ++i) if (cnt[i])
        now.eb(i, cnt[i]);
    for (int t = 0; t < n - 1; ++t) {
        int pre = -1;
        vector <pii> v;
        for (int i = 0; i < now.size(); ++i) {
            int x, c; tie(x, c) = now[i];
            if (pre == -1) {
                if (c > 1)
                    v.eb(0, c - 1);
            } else {
                v.eb(x - pre, 1);
                if (c > 1)
                    v.eb(0, c - 1);
            }
            pre = x;
        }
        sort(all(v));
        vector <pii> nxt;
        for (auto [i, c] : v) {
            if (!nxt.empty() && nxt.back().X == i)
                nxt.back().Y += c;
            else
                nxt.eb(i, c);
        }
        now = nxt;
    }
    cout << now.back().X << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}