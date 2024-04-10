#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 3000 + 5;
const ll maxA = 5000 + 10;

bool prime[maxA];
ll a[maxA][669 + 10], nex[maxA][669 + 10];
ll b[maxA], opt[669 + 10];
ll Sum[maxA];

int main(){
	ios_base::sync_with_stdio(false);
	ll n = 5000;
	for (ll i = 1; i <= n; i++)
		prime[i] = 1;
	prime[1] = 0;
	for (ll i = 2; i <= n; i++)
		for (ll j = i * i; j <= n; j += i)
			prime[j] = 0;
	vector<ll> p;
	for (ll i = 2; i <= n; i++)
		if (prime[i] == 1)
			p.push_back(i);
	reverse(p.begin(), p.end());
	ll m = p.size();
	for (ll i = 1; i <= n; i++){
		for (ll j = 0; j < m; j++){	
			for (ll x = p[j]; x <= i; x += p[j]){
				ll y = x;
				while (y % p[j] == 0){
					a[i][j] ++;
					y /= p[j];
				}
			}
		}
	}
	ll c;
	cin >> c;
	for (ll i = 1; i <= c; i++){
		ll k;
		cin >> k;
		k = max(k, 1ll);
		b[k] ++;
	}
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j < m; j++)
			Sum[i] += a[i][j];
	ll ansroot = 0;
	for (ll i = 1; i <= n; i++)
		ansroot += 1ll * Sum[i] * b[i];
	ll ans = ansroot;
	for (ll i = 1; i <= n; i++){
		ll L = 1, R = n;
		ll tot = ansroot, sumin = c, sumout = 0;
		memset(opt, 0, sizeof opt);
		for (ll j = 0; j < m; j++){
			while (opt[j] < a[i][j]){
				opt[j] ++;
				while (a[L][j] == opt[j] - 1){
					sumin -= b[L];
					sumout += b[L];
					L ++;
				}
				tot -= sumin;
				tot += sumout;
				ans = min(ans, tot);
			}
			while (a[R][j] > opt[j]){
				sumin -= b[R];
				sumout += b[R];
				R --;
			}
		}
	}
	cout << ans << endl;
}