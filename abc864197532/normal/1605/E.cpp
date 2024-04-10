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
const int mod = 998244353, N = 1000087, logN = 20, K = 111;

int main () {
    owo;
    int n;
    cin >> n;
    vector <lli> a(n + 1), b(n + 1), c(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    c[0] = c[1] = 0;
    vector <lli> pos;
    lli ans = 0;
    for (int i = 2; i <= n; ++i) {
        lli x = b[i] - a[i], y = -c[i];
        // x + ya
        if (y == 0) {
            ans += abs(x);
        } else if (y == 1) {
            pos.pb(x);
        } else {
            pos.pb(-x);
        }
        for (int j = i; j <= n; j += i) {
            a[j] += x, c[j] += y;
        }
    }
    sort(rall(pos));
    vector <pair <int, int>> query;
    int q;
    cin >> q;
    for (int i = 0, x; i < q; ++i) {
        cin >> x, query.eb(x - a[1], i);
    }
    sort(all(query));
    vector <lli> tans(q, 0);
    // |x + a|
    lli m = 0, k = 0;
    for (lli i : pos) {
        m--, k -= i;
    }
    test(pos, m, k);
    for (int i = 0, j = 0; j < q; ++j) {
        while (i < pos.size() && query[j].X + pos[i] > 0) {
            m += 2, k += pos[i++] * 2;
        }
        test(i, query[j].X);
        tans[query[j].Y] = ans + m * query[j].X + k + abs(query[j].X);
    }
    for (lli i : tans)
        cout << i << '\n';
}