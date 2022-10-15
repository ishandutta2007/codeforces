#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int a[n], p[n];
	for(int i = 0; i < n; i++)
		cin >> a[i] >> p[i];

	ll ans = 0;
	ll sum[n];
	for(int i = 0; i < n; i++){
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
	}

	int r = n - 1;
	while(r >= 0){
		int a = 0;
		for(int i = 1; i <= r; i++)
			if(p[i] < p[a])
				a = i;
		ans += 1LL * p[a] * (sum[r] - (a == 0 ? 0 : sum[a - 1]));
		r = a - 1;
	}

	cout << ans;

}