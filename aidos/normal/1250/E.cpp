#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxk = 11;
const int maxn = 1000100;
ll a[1000100];
int n;
ll b[1000100];
ll calc(ll x) {
	for(int i = 0; i < n; i++) {
		b[i] = a[i] % x;
	}
	ll ans = 0;
	for(int i = 0; i < n; ) {
		if(b[i] == 0) {
			i++;
			continue;
		}
		int j = i;
		ll ss = 0;
		while(i < n && ss < x) {
			ss += b[i];
			i++;
		}
		ll t = x/2;
		ll p = -1;
		ll cur = 0;
		i--;
		for(int k = j; k <= i; k++) {
			cur += b[k];
			if(cur >= t) {
				p = k;
				break;
			}
		}
		ll mm = x;
		ll cost1 = 0;
		for(int k = j; k <= i; k++) {
			ll y = min(mm, b[k]);
			mm -= y;
			if(k < p) cost1 += (p-k) * y;
			else cost1 += (k-p) * y;
		}
		t = (x+1)/2;
		ll p2 = -1;
		cur = 0;
		for(int k = j; k <= i; k++) {
			cur += b[k];
			if(cur >= t) {
				p2 = k;
				break;
			}
		}
		mm = x;
		ll cost2 = 0;
		for(int k = j; k <= i; k++) {
			ll y = min(mm, b[k]);
			mm -= y;
			if(k < p2) cost2 += (p2-k) * y;
			else cost2 += (k-p2) * y;
		}
		
		ans += min(cost1, cost2);
		b[i] = ss % x;
	}
	return ans;
}

int main () {
 	scanf("%d", &n);
 	ll s = 0;
 	for(int i = 0; i < n; i++) {
 		scanf("%lld", &a[i]);
 		s += a[i];
 	}
 	ll ans = s * n + n;
 	vector<ll> pr;
 	for(ll i = 2; i*i<= s; i++) {
 		if(s % i == 0) {
 			pr.pb(i);
 			while(s % i == 0) {
 				s/=i;
 			}
 		}
 	}
 	if(s > 1) {
 		pr.pb(s);
 	}
 	if(pr.size() == 0) {
 		cout << -1 << "\n";
 		return 0;
 	}
 	for(int i = 0; i < pr.size(); i++) {
 		ans = min(ans, calc(pr[i]));
 	}
 	cout << ans << "\n";
 	return 0;
}