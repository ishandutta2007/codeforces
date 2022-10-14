#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
int MOD = 998244353;

long long Div (int a, int b) {
	int a1 = b, a2 = MOD, a3 = 1, a4 = 0;
	while (a2 != 0) {
		tie(a3, a4) = mp(a4, a3 - a1 / a2 * a4);
		tie(a1, a2) = mp(a2, a1 % a2);
	}
	return 1ll * a * a3 % MOD;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, tmp;
	cin >> n;
	vector <int> nums[n];
	lli ans = 0;
	vector <int> times(1 << 20, 0);
	fop (i,0,n) {
		int k;
		cin >> k;
		fop (j,0,k) {
			cin >> tmp;
			nums[i].pb(tmp-1);
			times[tmp-1]++;
		}
	}
	fop (i,0,n) {
		int aa = 0;
		for (int j : nums[i]) {
			aa += times[j];
		}
		ans = (ans + Div(Div(aa, n), nums[i].size())) % MOD;
	}
	ans = Div(ans, n);
	if (ans < 0) ans += MOD;
 	cout << ans << endl;
}