#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

void solve() {
    int n;
    cin >> n;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].X >> a[i].Y;
    vector <int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j) {
        return a[i] < a[j];
    });
    vector <int> ans(n, -1), id2 = id;
    vector <pii> b = a;
    for (int t : {0, 1}) {
    	set <pii> cur;
		for (int i = 0, j = 0; i < n; ++i) {
			while (j < n && a[id[j]].X < b[id2[i]].X) cur.insert({a[id[j]].Y, id[j] + 1}), j++;
			auto it = cur.lower_bound({b[id2[i]].Y, -1});
			if (it != cur.begin()) ans[id2[i]] = (--it)->Y;
		}
		for (pii &A : b) swap(A.X, A.Y);
		sort(all(id2), [&](int i, int j) {
		    return b[i] < b[j];
		});
	}
    printv(ans);
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