
// Dennis - Toney
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll A[N];

ll Solve(ll n){
	ll al = 0, d = 1;
	while(n % 2 == 0){
		al ++;
		d *= 2;
		n/=2;
	}
	if(n == 1) return -1;
	ll ans = d + d;
	ll x = (n + 1) / 2;
	if(x <= d)
		return n;
	return ans;
}

bool Check(ll x, ll n){
	if(x == -1) return true;
	ll lw = (x + 1) * x / 2ll;
	if(lw <= n && (lw - n) % x == 0)
		return true;
	return false;
}

int Main(){
	ll n; cin >> n;
	// for(int i = 1; i <= n; i++){
	// 	cout << i << " : " << Solve(i) << endl;
	// 	assert(Check(Solve(i), i));
	// }
	cout << Solve(n) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}