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

	string s;
	cin >> s;

	ll ans = *s.rbegin() - '0';

	ll pow = 1;

	for(int i = (int) s.size() - 2; i >= 0; i--){
		pow = (pow * 4) mod;
		ans = (ans * 2) mod;
		if(s[i] == '1')
			ans = (ans + pow) mod;

	}
	cout << ans << endl;

}