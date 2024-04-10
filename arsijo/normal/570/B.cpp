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
typedef int** matrix;
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

	int m, n;
	cin >> m >> n;

	cout << max(1, (n - 1 >= m - n ? n - 1 : n + 1));

}