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
const ll MAX = 3e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#ifdef DEBUG
//output;
#endif
#else

#endif

	int n;
	cin >> n;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	cout << ar[1] - ar[0] << " " << ar[n - 1] - ar[0] << endl;
	for(int i = 1; i < n - 1; i++)
		cout << min(ar[i + 1] - ar[i], ar[i] - ar[i - 1]) << " " << max(ar[n - 1] - ar[i], ar[i] - ar[0]) << endl;
	cout << ar[n - 1] - ar[n - 2] << " " << ar[n - 1] - ar[0] << endl;



}