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

// int dif[N], a[N];

int sum = 0;


ll a[N];
ll jm[N];
int Main(){
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	fill(jm, jm + n + 1, 0);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(jm[i] < a[i] - 1){
			ans += (a[i] - 1) - jm[i];
			jm[i] = a[i] - 1;
		}
		for(int j = i + 2; j <= min(i + a[i], n); j++) jm[j] ++;
		jm[i + 1] += (jm[i] - (a[i] - 1));
		jm[i + 1] = min(Inf, jm[i + 1]);
	}
	cout << ans << '\n';
	return 0;
	// cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	ll u, v;
	for(int i = 0; i < q; i++){
		cin >> u >> v;
		if(u > v) {
			cout << "NO\n";
			continue;
		}
		ll d = v - u;
		while(d > 0){
			ll mx = (1ll << 32);
			while((mx > 0) && ((mx & u) == 0)) mx /= 2;
			if(mx == 0){
				d = -1;
			} else {
				if(d >= mx){
					u += mx;
					d -= mx;
					mx *= 2ll;
				} else {
					u -= mx;
					v -= mx;
				}
			}
			// cerr << "! " << u << ' ' << v << ' ' << mx << '\n';
		}
		cout << (d == 0 ? "YES\n" : "NO\n");
	}
	return 0;
}