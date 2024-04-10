#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;
const int ITER = 20;
const int LIM = 1;

int N;
ll a[MAXN];

int solve(int x) {
	ll res = MAXN;
	for (int i = -LIM; i <= LIM; i++) {
		ll tmp = a[x] + i;
		if (tmp < 0)
			continue;
		vector <ll> p;
		for (ll j = 2; j * j <= tmp; j++) {
			if (tmp % j)
				continue;
			p.push_back(j);
			while (!(tmp % j))
				tmp /= j;
		}
		if (tmp > 1)
			p.push_back(tmp);
		for (auto it : p) {
			ll cost = 0;
			for (int j = 0; j < N; j++) 
				cost += a[j] < it ? it - a[j] : min(a[j] % it, it - a[j] % it);
			res = min(res, cost);
		}
	}
	return res;
}

int main() {
	scanf("%d", &N); 
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += a[i] % 2;
		
	for (int i = 0; i < ITER; i++) 
		ans = min(ans, solve(uniform_int_distribution <int> (0, N - 1)(rng)));
		
	printf("%d\n", ans);
	
	return 0;
}