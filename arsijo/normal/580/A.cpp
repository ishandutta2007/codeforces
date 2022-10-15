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
#define x first
#define y second
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-5;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 200;
#else
const ll MAX = 200;
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int ans = 1;
	int n;
	cin >> n;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	int t = ans = 1;
	for(int i = 1; i < n; i++){
		t = (ar[i] >= ar[i - 1] ? t + 1 : 1);
		ans = max(ans, t);
	}

	cout << ans;

}