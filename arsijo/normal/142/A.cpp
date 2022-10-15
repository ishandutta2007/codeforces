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
const ll MAX = 1e6 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	ll n;
	cin >> n;

	ll min_ans = LONG_LONG_MAX;

	for(ll i = 1; i * i * i <= n; i++){
		if(n % i != 0)
			continue;
		ll g = n / i;
		for(ll j = sqrt(g); j > 0; j--)
			if(g % j == 0){
				min_ans = min(min_ans, (i + 1) * (j + 2) * (g / j + 2));
			}
	}

	cout << min_ans - n << " " << n * 8 + 9 << endl;

}