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
const int mod = 998244353, N = 100100, logN = 20, M = 6e6;

vector <int> pt[N];

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        // a_i / p_i >= x
        // a_i >= x * p_i
        // p_i <= a_i / x
        // p_i = min(a[i] / x, k)
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        n = unique(all(a)) - a.begin(); a.resize(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            pt[2].pb(i);
            mx = max(mx, a[i] / min(a[i], k));
        }
        int ans = mx - 1;
        for (int x = 2; x <= a[0]; ++x) {
            for (int i : pt[x]) {
                mx = max(mx, a[i] / min(a[i] / x, k));
                // a[i] / x change
                if (a[i] / x != a[i] / (x + 1)) {
                    if (x + 1 <= a[0])
                        pt[x + 1].pb(i);
                } else {
                    int now = a[i] / x;
                    // a[i] / y < now
                    // a[i] < y * now
                    // y > a[i] / now
                    if (a[i] / now + 1 <= a[0])
                        pt[a[i] / now + 1].pb(i);
                }
            }
            pt[x] = vector<int>();
            ans = min(ans, mx - x);
        }
        pt[2] = vector<int>();
        cout << ans << '\n';
    }
}