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

#ifdef LOCAL
const ll MAX = 1000;
//#define DEBUG
#else
const ll MAX = 1e5 + 3;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int ar[6];
	for(int i = 0; i < 6; i++)
		cin >> ar[i];

	cout << sqr(ar[0] + ar[1] + ar[2]) - sqr(ar[0]) - sqr(ar[2]) - sqr(ar[4]);

}