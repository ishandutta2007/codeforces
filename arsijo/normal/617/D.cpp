#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-7;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

ll n, x1, y1, x2, y2;
ll x[2000], y[2000];

ll dist(ll x1, ll y1, ll x2, ll y2){
	return sqr(x1 - x2) + sqr(y1 - y2);
}

ll check(ll r1){
	ll r2 = 0;
	for(int i = 0; i < n; i++){
		if(sqr(x[i] - x1) + sqr(y[i] - y1) > r1){
			r2 = max(r2, dist(x[i], y[i], x2, y2));
		}
	}
	return r1 + r2;
}

bool in(int a, int b, int c){
	if(b > c)
		swap(b, c);
	return b < a && a < c;
}

int main() {

	cout.precision(11);

	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#else

#endif

	int x[3], y[3];
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	if((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])){
		cout << 1;
	}else{
		for(int i = 0; i < 3; i++){
			int a = (i == 0 ? 1 : 0);
			int b = (a + 1 == i ? a + 2 : a + 1);
			if((y[a] == y[b] && !in(x[i], x[a], x[b])) || (x[a] == x[b] && !in(y[i], y[a], y[b])) ){
				cout << 2;
				return 0;
			}
		}
		cout << 3;
	}

}