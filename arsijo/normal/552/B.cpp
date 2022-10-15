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

	ll n;
	cin >> n;

	ll a = 9;

	ll ans = 0;
	for(int i = 1; i <= 100; i++){
		if(n <= a){
			ans += (ll) (n * i);
			break;
		}else{
			ans += (ll) (a * i);
			n -= a;
			a *= 10;
		}
	}
	cout << ans << endl;


}