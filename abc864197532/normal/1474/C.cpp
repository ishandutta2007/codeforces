#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n * 2);
    for (int i = 0; i < n * 2; ++i) cin >> a[i];
    sort(all(a));
    for (int j = 0; j < n * 2 - 1; ++j) {
        multiset <int> s;
        for (int i = 0; i < n * 2; ++i) if (i != 2 * n - 1 && i != j) s.insert(a[i]);
        int old = a[n * 2 - 1];
        vector <pii> ans = {mp(a[n * 2 - 1], a[j])};
        while (s.size()) {
            int x = *--s.end();
            s.erase(--s.end());
            auto it = s.lower_bound(old - x);
            if (it != s.end() && *it == old - x) {
                s.erase(s.lower_bound(old - x));
                ans.eb(old - x, x);
                old = x;
            } else {
                break;
            }
        }
        if (s.empty()) {
            cout << "YES\n";
            cout << a[n * 2 - 1] + a[j] << endl;
            for (auto A : ans) cout << A << endl;
            return;
        }
    }
    cout << "NO\n";
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