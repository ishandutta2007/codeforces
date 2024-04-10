#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const ll inf = 2e12;

int n;
ll k;
ll a[maxn], cpy[maxn];
int b[maxn], t[maxn];
int val[maxn];

bool check(ll x){
	for (int i = 1; i <= n; i++)
		a[i] = cpy[i];
	memset(val, 0, sizeof val);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		while (true){
			ll t = a[i] / b[i];
			if (t >= k - 1)
				break;
			val[t] ++;
			a[i] += x;
			cnt ++;
			if (cnt > k)
				return 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < k; i++){
		sum += val[i];
		if (sum > i + 1)
			return 0;
	}
	return 1;
}

int main(){
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cpy[i] = a[i];
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	ll lo = -1, hi = inf;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	if (hi == inf)
		hi = -1;
	printf("%lld\n", hi);
}