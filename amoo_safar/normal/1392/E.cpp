// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll A[30][30];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int t = (i + j - 2);
			ll X = 1ll << t;
			cout << (i & 1 ? 0 : X) << ' ';
			A[i][j] = (i & 1 ? 0 : X);
		}
		cout << endl;
	}
	ll q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll k;
		cin >> k;
		ll x = 1, y = 1;
		cout << x << ' ' << y << endl;
		ll bt = 1;
		for(int c = 0; c < n + n - 2; c++){
			if(x == n){
				y ++;
			} else if(y == n){
				x ++;
			} else {
				ll t = k >> bt & 1;
				if(min(A[x + 1][y], 1ll) == t) x++;
				else y ++;
			}

			cout << x << ' ' << y << endl;
			bt ++;
		}
	}
	return 0;
}