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
const int mod = 998244353, N = 1e6 + 5, logN = 20, K = 111, C = 1e9;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
    owo;
    int n;
    cin >> n;
    vector <pii> a(n);
    map <pii, int> active;
    for (int i = 0; i < n; ++i)
        cin >> a[i], active[a[i]] = i;
    vector <pii> b;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 4; ++k) {
            int x = a[i].X + dx[k], y = a[i].Y + dy[k];
            if (active.count(mp(x, y)))
                continue;
            b.eb(x, y);
        }
    }
    sort(all(b)), b.resize(unique(all(b)) - b.begin());
    queue <pair <pii, pii>> q;
    for (pii a : b)
        q.push(mp(a, a));
    vector <pii> ans(n);
    while (!q.empty()) {
        int rtx, rty, x, y; tie(rtx, rty) = q.front().X, tie(x, y) = q.front().Y; q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!active.count(mp(nx, ny)))
                continue;
            int id = active[mp(nx, ny)];
            q.emplace(mp(rtx, rty), mp(nx, ny));
            ans[id] = mp(rtx, rty);
            active.erase(mp(nx, ny));
        }
    }
    for (pii i : ans)
        cout << i.X << ' ' << i.Y << '\n';
}