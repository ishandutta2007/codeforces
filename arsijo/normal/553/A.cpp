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
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 1001;
const ld E = 1e-11;

int main() {

	sync;
	//input;

	int C[MAX][MAX];
	ms(C);

	for(int i = 0; i < MAX; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) mod;
	}

	ll ans = 1, k;
	cin >> k;

	ll sum = 0;
	cin >> sum;

	while(--k){
		int a;
		cin >> a;
		sum += a;
		ans = (ll) (ans * (C[sum - 1][a - 1])) mod;
	}

	cout << ans;

}