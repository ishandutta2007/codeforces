#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1e5 + 10;
const ll inf = 4e18;

int n;
int a[maxn], b[maxn];

ll get(ll x, ll y){
	return y + 3ll*x - 3ll*x*x - 1;
}

ll check(ll bs){
	ll ret = 0;
	for (int i = 1; i <= n; i++){
		int lo = 0, hi = a[i] + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (get(mid, a[i]) > bs)
				lo = mid;
			else
				hi = mid;
		}
		b[i] = lo;
		ret += lo;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll lo = -inf, hi = inf;
	ll x = 0;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		x = check(mid);
		if (x > k)
			lo = mid;
		else
			hi = mid;
	}
	x = check(hi);
	for (int i = 1; i <= n; i++){
		if (x < k and get(b[i]+1, a[i]) == hi){
			b[i] ++;
			x ++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i == n];
}