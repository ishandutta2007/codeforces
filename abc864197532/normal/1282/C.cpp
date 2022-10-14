#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define endl '\n'

void solve() {
	lli n, T, a, b, tmp;
	cin >> n >> T >> a >> b;
	vector <pii> nums(n), must(n);
	fop (i,0,n) cin >> nums[i].second;
	fop (i,0,n) cin >> nums[i].first;
	sort(nums.begin(), nums.end());
	int aa[2] = {0, 0};
	fop (i,1,n) {
		aa[nums[i-1].second]++;
		must[i] = mp(aa[0], aa[1]);
	}
	aa[nums[n-1].second]++;
	if (T >= aa[0] * a + aa[1] * b) {
		cout << n << endl;
		return;
	}
	lli ans = 0;
	fop (i,0,n) {
		lli tt = nums[i].first - 1 - must[i].first * a - must[i].second * b;
		if (tt < 0) continue;
		if (tt / a > aa[0] - must[i].first) {
			tt = nums[i].first - 1 - aa[0] * a;
			ans = max(ans, aa[0] + tt / b);
		} else {
			ans = max(ans, i + tt / a);
		}
	}
	cout << ans << endl;
}



int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}