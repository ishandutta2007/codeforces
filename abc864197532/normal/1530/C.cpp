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
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    vector <int> prea = {0}, preb = {0};
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    for (int i : a) prea.pb(prea.back() + i);
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(all(b));
    for (int i : b) preb.pb(preb.back() + i);
    auto geta = [&](int len) {
        if (len <= n) return prea[len];
        return prea[len] + 100 * (len - n);
    };
    auto getb = [&](int len) {
        if (len < 0) return 0;
        return preb[len];
    };
    for (int ans = 0; ; ++ans) {
        int len = (n + ans) / 4;
        if (prea.back() - geta(len) + ans * 100 >= preb.back() - getb(len - ans)) {
            cout << ans << endl;
            break;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}