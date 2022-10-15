#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator si;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 1001;
///#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

bool prime(int n){
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
	return true;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#ifdef DEBUG
//output;
#endif
#else

#endif

	int n, k;
	cin >> n >> k;

	int ar[n];
	map<ll, ll> m1, m2;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> ar[i];
		ll g = 1LL * ar[i] * k;
		ans += m2[ar[i]];
		if(g <= INT_MAX){
			m2[g] += m1[ar[i]];
			m1[g] += 1;
		}
	}

	cout << ans;

}