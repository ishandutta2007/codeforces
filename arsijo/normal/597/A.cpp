#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1000;
#else
const int MAX = 2e5 + 1;
#endif

int get(ll a){
	return a < 0 ? -1 : 1;
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ll k, a, b;
	cin >> k >> a >> b;

	if(get(a) != get(b)){
		cout << 1 + abs(a) / k + abs(b) / k;
	}else{
		a = abs(a);
		b = abs(b);
		if(a > b)
			swap(a, b);
		if(a == 0){
			cout << b / k + 1;
		}else{
			cout << b / k - (a - 1) / k;
		}
	}

}