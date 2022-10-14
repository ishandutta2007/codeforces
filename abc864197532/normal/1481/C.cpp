#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 400008, logN = 17, K = 333;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> need[n], a(n), b(n), c(m), cyc(n, -1);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i], --b[i];
        if (a[i] != b[i]) {
            need[b[i]].pb(i);
        } else {
            cyc[b[i]] = i;
        }
    }
    vector <int> ans(m, -1);
    vector <int> waiting;
    for (int i = 0; i < m; ++i) cin >> c[i], --c[i];
    int lst = -1;
    for (int i = m - 1; ~i; --i) {
        if (need[c[i]].empty()) {
            if (~lst) {
                ans[i] = lst;
            } else if (~cyc[c[i]]) {
                ans[i] = cyc[c[i]];
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            int x = need[c[i]].back(); need[c[i]].pop_back();
            ans[i] = x;
        }
        lst = ans[i];
    }
    for (int i = 0; i < m; ++i) {
        a[ans[i]] = c[i];
    }
    if (a == b) {
        cout << "YES\n";
        for (int i : ans) cout << i + 1 << ' ';
        cout << endl;
    } else {
        cout << "NO\n";
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