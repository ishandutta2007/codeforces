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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;

	int ar[b.size()];
	for(int i = 0; i < (int) b.size(); i++){
		ar[i] = 0;
		for(int j = 0; j < (int) a.size(); j++)
			if(a[j] == b[(i + ar[i]) % b.size()])
				ar[i]++;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += ar[ans % b.size()];

	cout << ans / m / b.size();

}