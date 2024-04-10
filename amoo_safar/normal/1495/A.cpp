// vaziat meshki-ghermeze !
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

int Main(){

	int n;
	cin >> n;
	vector<ll> X, Y;
	X.clear(); Y.clear();
	ll x, y;
	for(int i = 0; i < n+n; i++){
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		if(x == 0) Y.pb(y);
		else X.pb(x);
	}
	// debug(X.size());
	sort(all(X));
	sort(all(Y));
	ld ans = 0;
	for(int j = 0; j < n; j++){
		// debug(X[j]);		// debug(Y[j]);
		ans += sqrt(X[j]*X[j] + Y[j]*Y[j]);
	}

	cout << fixed << setprecision(16) << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();

	return 0;
}