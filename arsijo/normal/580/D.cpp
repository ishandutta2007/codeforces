#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
#define x first
#define y second
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-5;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 10;
#else
const ll MAX = 19;
#endif

ll res[1 << MAX][MAX], ar[MAX][MAX], a[MAX], n, m;
vector<int> vec;

void make(int pos, int val, int left) {
	if (left == 0)
		vec.push_back(val);
	if (left == 0 || pos == n)
		return;
	make(pos + 1, val | (1 << pos), left - 1);
	make(pos + 1, val, left);
}

ll solve(int mask, int last) {
	//cout << "solve " << mask << " " << last << endl;
	if (last != -1 && res[mask][last] != -1)
		return res[mask][last];
	//cout << mask << endl;
	ll ans = -1e14;
	for (int i = 0; i < n; i++)
		if ((mask & (1 << i)) != 0) {
			ans = max(ans,
					solve(mask ^ (1 << i), i) + a[i]
							+ (last == -1 ? 0 : ar[last][i]));
		}
	//cout << mask << " " << last << " " << ans << endl;
	return res[mask][last] = ans;
}

ll solve() {
	ll ans = 0;
	make(0, 0, m);
	for (int i = 0; i < (int) vec.size(); i++) {
		ans = max(ans, solve(vec[i], -1));
	}
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	for(int i = 0; i < (1 << MAX); i++)
	for(int j = 0; j < MAX; j++)
	res[i][j] = -1;

	ms(ar);

	int k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	cin >> a[i];

	while(k--) {
		int l, r, v;
		cin >> l >> r >> v;
		ar[l - 1][r - 1] = v;
	}

	for(int i = 0; i < MAX; i++)
	res[0][i] = 0;

	cout << solve();

}