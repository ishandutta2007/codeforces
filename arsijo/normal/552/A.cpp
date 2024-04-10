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
const int MAX = 400010;
const ld E = 1e-11;

int main() {

	sync;

	int n;
	cin >> n;

	ll ans = 0;
	while(n--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ans += (x2 - x1 + 1) * (y2 - y1 + 1);
	}

	cout << ans;

}