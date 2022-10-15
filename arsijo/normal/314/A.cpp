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

	int nn;
	ll k;
	cin >> nn >> k;

	int n = nn;

	ll ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	ll first = 0;

	for(int i = 1, j = 1; i <= n; i++, j++){
		ll second = (i - 1) * ar[j - 1] * (n - i);
		ll res = first - second;
		if(res < k){
			n--;
			i--;
			cout << j << endl;
		}else{
			first += (ll) ar[j - 1] * (i - 1);
		}
	}

}