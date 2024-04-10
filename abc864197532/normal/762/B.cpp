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
const int mod = 1e9 + 7, N = 400005, logN = 18, G = 3;

int main () {
    owo;
    int a, b, c, q;
    cin >> a >> b >> c >> q;
    vector <int> cost[2];
    while (q--) {
        int x; string s;
        cin >> x >> s;
        if (s == "USB")
            cost[0].pb(x);
        else
            cost[1].pb(x);
    }
    sort(rall(cost[0])), sort(rall(cost[1]));
    lli ans1 = 0, ans2 = 0;
    while (a && !cost[0].empty()) {
        a--, ans1++, ans2 += cost[0].back(), cost[0].pop_back();
    }
    while (b && !cost[1].empty()) {
        b--, ans1++, ans2 += cost[1].back(), cost[1].pop_back();
    }
    vector <int> remain(cost[0].size() + cost[1].size());
    merge(all(cost[0]), all(cost[1]), remain.begin(), [&](int i, int j) {
        return i > j;
    });
    while (c && !remain.empty()) {
        c--, ans1++, ans2 += remain.back(), remain.pop_back();
    }
    cout << ans1 << ' ' << ans2 << '\n';
}