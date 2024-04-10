#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int now = 0;
	int ans[n];
	bool is2 = true;
	while (now < 10) {
		bool is = true;
		is2 = true;
		int now2 = now, now3 = 0;
		fop (i,0,n) {
			if (s[i] - '0' < now) {
				if (now3 > s[i] - '0') {
					is2 = false;
					break;
				}
				now3 = s[i] - '0';
				ans[i] = 1;
			} else if (s[i] - '0' == now) {
				if (is) ans[i] = 2;
				else ans[i] = 1, now3 = now;
			} else {
				is = false;
				if (now2 > s[i] - '0') {
					is2 = false;
					break;
				}
				now2 = s[i] - '0';
				ans[i] = 2;
			}
		}
		if (is2) break;
		now++;
	}
	if (!is2) {
		cout << '-' << endl;
		return;
	}
	fop (i,0,n) cout << ans[i];
	cout << '\n';
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}