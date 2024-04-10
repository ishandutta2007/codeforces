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
const int mod = 1e9 + 7, N = 100005, logN = 18, G = 3;

int main () {
    owo;
    int n, m;
    lli t;
    cin >> n >> m >> t;
    vector <int> pos(n), dir(n), ed(n);
    lli cur = 0, M = 1ll * n * m;
    for (int i = 0; i < n; ++i) {
        cin >> pos[i], --pos[i];
        char c; cin >> c;
        dir[i] = c == 'L' ? -1 : 1;
        (cur += dir[i] * t) %= M;
        (cur += pos[i]) %= M;
        ed[i] = (pos[i] + dir[i] * t % m + m) % m;
        (cur -= ed[i]) %= M;
    }
    if (cur < 0)
        cur += M;
    int cyc = cur / m;
    vector <int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        return pos[i] < pos[j];
    });
    sort(all(ed));
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[ord[i]] = ed[(i + cyc) % n] + 1;
    }
    printv(all(ans));
}