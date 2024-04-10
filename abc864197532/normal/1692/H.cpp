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
const int mod = 1e9 + 7, N = 200001, logN = 18, B = 550;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector <int> v = a;
        sort(all(v)), v.resize(unique(all(v)) - v.begin());
        for (int &i : a)
            i = lower_bound(all(v), i) - v.begin();
        vector <vector <int>> p(v.size());
        for (int i = 0; i < n; ++i)
            p[a[i]].pb(i);
        int ans = 1, ansx = a[0], ansl = 0, ansr = 0;
        for (int x = 0; x < v.size(); ++x) {
            // max (r - l + 1) * 2 - (p[r] - p[l] + 1)
            // max (r * 2 - p[r]) - (l * 2 - p[l]) + 1
            int mn = -p[x][0], pt = 0;
            for (int i = 1; i < p[x].size(); ++i) {
                int val = i * 2 - p[x][i];
                if (val - mn + 1 > ans) {
                    ans = val - mn + 1, ansx = x;
                    ansl = p[x][pt], ansr = p[x][i];
                }
                if (mn > val)
                    mn = val, pt = i;
            }
        }
        cout << v[ansx] << ' ' << ansl + 1 << ' ' << ansr + 1 << '\n';
    }
}