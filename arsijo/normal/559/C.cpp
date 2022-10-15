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
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5 + 1;
//#define DEBUG
#else
const ll MAX = 3e5 + 1;
#endif

ll fac[MAX], r[MAX];

ll pow_mod(ll a, ll n, ll md) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (ll) (res * a) % md;
			n--;
		} else {
			a = (ll) (a * a) % md;
			n >>= 1;
		}
	}
	return res;
}

void pre() {

	fac[0] = 1;
	r[0] = pow_mod(1, MOD - 2, MOD);

	for(int i = 1; i < MAX; i++){
		fac[i] = (fac[i - 1] * i) mod;
		r[i] = pow_mod(fac[i], MOD - 2, MOD);
	}

}

int C(int n, int k){
	int res = (fac[n] * 1ll * r[k]) mod;
	return (res * 1ll * r[n - k]) mod;
}

int get(int n, int m){
	return C(n + m - 2, n - 1);
}

vector<ii> vec;

int *ans;

int solve(int a){

	if(ans[a] != -1)
		return ans[a];

	int n = vec[a].first, m = vec[a].second;
	int res = get(n, m);
	for(int i = 0; i < (int) vec.size(); i++)
		if(vec[i].first <= n && vec[i].second <= m && i != a){
			res -= (solve(i) * 1ll * get(n - vec[i].first + 1, m - vec[i].second + 1)) mod;
			if(res < 0)
				res += MOD;
		}

	return ans[a] = res;

}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	pre();

	int h, w, n;
	cin >> h >> w >> n;

	vec.reserve(n + 1);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	vec.push_back(make_pair(h, w));
	sort(vec.begin(), vec.end());

	ans = new int[n + 1];
	for(int i = 0; i <= n; i++)
		ans[i] = -1;

	cout << solve(n);

}