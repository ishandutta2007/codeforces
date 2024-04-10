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
const ll MAX = 1e3;
//#define DEBUG
#else
const ll MAX = 3e4 + 10;
#endif

const int MD = 400;

int used[MAX][MD * 2 + 1], dp[MAX][MD * 2 + 1], ar[MAX], d;

int solve(int pos, int di){
	if(pos >= MAX)
		return 0;
	if(used[pos][di - d + MD]++)
		return dp[pos][di - d + MD];
	return dp[pos][di - d + MD] = max(max(solve(pos + di, di), solve(pos + di, di + 1)), (di == 1 ? 0 : solve(pos + di, di - 1))) + ar[pos];
}

int main() {

	sync;
	cout.precision(20);

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n;
	cin >> n >> d;
	ms(ar);

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ar[a]++;
	}

	ms(used);

	cout << solve(0, d);

}