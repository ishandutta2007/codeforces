// har ki ro didi goft mikhad beshe meslemon !
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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
ll ps[N];

int Main(){
	ll k, n;
	cin >> n >> k; k ++;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + ((i - 1) / k) * a[i];
	}
	ll s = 0, s2 = 0;
	ll ans = ps[n];
	for(int i = n; i > 0; i--){
		s2 += s;
		s += a[i];
		// debug(s2);
		// //debug(s);
		// debug(s2 + s * (((i - 1) - 1 + k) / k));
		ans = max(ans, s2 + s * (((i - 1) - 1 + k) / k) + ps[i - 1]);
	}
	ans = max(ans, s2);
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	T = 1;
	// cin >> T;
	for(int i = 0; i < T; i++){
		Main();
	}
	return 0;
}