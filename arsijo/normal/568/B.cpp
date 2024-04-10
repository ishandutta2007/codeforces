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
const ll MAX = 101;
///#define DEBUG
#else
const ll MAX = 4001;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	ll c[MAX][MAX];
	ms(c);

	c[0][0] = 1;

	for(int i = 1; i < MAX; i++){
		for(int j = 0; j <= i; j++)
			c[i][j] = ((j == 0 ? 0 : c[i - 1][j - 1]) + c[i - 1][j]) mod;
	}

	int n;
	cin >> n;

	int ar[n];
	ms(ar);

	ll ans[n];

	for(int i = 0; i < n; i++){
		ans[i] = 1;
		for(int j = 0; j < i; j++)
			ans[i] = (ans[i] + (c[i][j + 1] + 1) * ans[j]) mod;
	}

	cout << ans[n - 1];

}