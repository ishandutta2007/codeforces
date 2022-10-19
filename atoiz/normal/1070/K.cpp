#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s) freopen(string(s) + ".inp", "r", stdin), freopen(string(s) + ".out", "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e5 + 5;
int n, k, a[N], sum = 0;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fw (i, 0, n) cin >> a[i], sum += a[i];
	if (sum % k) {
		cout << "No";
		return 0;
	}
	vector<int> v;
	v.pb(-1);
	int each = sum / k, cur = 0;
	fw (i, 0, n) {
		cur += a[i];
		if (cur > each) {
			cout << "No";
			return 0;
		}
		if (cur == each) {
			cur = 0;
			v.pb(i);
		}
	}
	cout << "Yes\n";
	fw (i, 1, v.size()) cout << v[i] - v[i - 1] << " ";
	return 0;
}