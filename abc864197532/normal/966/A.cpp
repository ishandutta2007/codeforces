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
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

int main () {
    owo;
    int n, m, a, b, v;
    cin >> n >> m >> a >> b >> v;
    vector <int> stairs(a), e(b);
    for (int i = 0; i < a; ++i)
        cin >> stairs[i];
    for (int i = 0; i < b; ++i)
        cin >> e[i];
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << '\n';
            continue;
        }
        int d1 = 1 << 30, d2 = 1 << 30;
        {
            auto it = lower_bound(all(stairs), y1);
            if (it != stairs.end())
                d1 = min(d1, abs(*it - y1) + abs(*it - y2));
            if (it != stairs.begin())
                d1 = min(d1, abs(*prev(it) - y1) + abs(*prev(it) - y2));
        }
        {
            auto it = lower_bound(all(stairs), y2);
            if (it != stairs.end())
                d1 = min(d1, abs(*it - y1) + abs(*it - y2));
            if (it != stairs.begin())
                d1 = min(d1, abs(*prev(it) - y1) + abs(*prev(it) - y2));
        }
        {
            auto it = lower_bound(all(e), y1);
            if (it != e.end())
                d2 = min(d2, abs(*it - y1) + abs(*it - y2));
            if (it != e.begin())
                d2 = min(d2, abs(*prev(it) - y1) + abs(*prev(it) - y2));
        }
        {
            auto it = lower_bound(all(e), y2);
            if (it != e.end())
                d2 = min(d2, abs(*it - y1) + abs(*it - y2));
            if (it != e.begin())
                d2 = min(d2, abs(*prev(it) - y1) + abs(*prev(it) - y2));
        }
        int ans = 1 << 30;
        ans = min(ans, d1 + abs(x1 - x2));
        ans = min(ans, d2 + (abs(x1 - x2) + v - 1) / v);
        cout << ans << '\n';
    }
}