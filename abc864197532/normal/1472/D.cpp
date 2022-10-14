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
    vector <int> a[2];
    for (int i = 0, tmp; i < n; ++i) cin >> tmp, a[tmp & 1].pb(tmp);
    lli val[2] = {0, 0};
    sort(all(a[0]));
    sort(all(a[1]));
    int t = 0;
    while (a[0].size() && a[1].size()) {
    	if (a[t].back() > a[t ^ 1].back()) {
    		val[t] += a[t].back();
    		a[t].pop_back();
		} else {
			a[t ^ 1].pop_back();
		}
		t ^= 1;
	}
	while (!a[0].empty()) {
		if (t == 0) val[t] += a[0].back();
		a[0].pop_back();
		t ^= 1;
	}
	while (!a[1].empty()) {
		if (t == 1) val[t] += a[1].back();
		a[1].pop_back();
		t ^= 1;
	}
	if (val[0] > val[1]) cout << "Alice\n";
	else if (val[0] == val[1]) cout << "Tie\n";
	else cout << "Bob\n";
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