#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
ll pathSum[MAXN*20], val[MAXN];
ll factorUpto[MAXN];
int n, q;
bool isPrime(int k) {
	for (int i = 2; i*i <= k; i++) {
		if (k%i == 0) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		set<int> s;
		priority_queue<pair<ll, int> > pq;
 
		for (int i = 1; i < n; i++) {
			int v = gcd(i, n);
			s.insert(v);
		}
		vector<ll> factors;
		for (auto a : s) {
			if (isPrime(n/a)) {
				factors.push_back(a);
			}
		}
		int upto = 0;
		for (auto a : factors) {
			factorUpto[a] = upto;
			for (int i = 0; i < a; i++) {
				++upto;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &val[i]);
			for (auto f : factors) {
				int path = factorUpto[f] + i%f;
				pathSum[path] += (f*val[i]);
			}
		}
		for (int i = 0; i < upto; i++) {
			pq.push({pathSum[i], i});
		}
		printf("%lld\n", pq.top().first);
		for (int i = 0; i < q; i++) {
			int x;
			ll newVal;
			scanf("%d%lld", &x, &newVal);
			x--;
			for (auto f : factors) {
				int path = factorUpto[f] + x%f;
				pathSum[path] -= f*val[x];
				pathSum[path] += f*newVal;
				pq.push({pathSum[path], path});
			}
			val[x] = newVal;
 
			while (pathSum[pq.top().second] != pq.top().first) pq.pop();
			printf("%lld\n", pq.top().first);
		}
		//printf("upto %d\n", upto);
		fill_n(pathSum, upto, 0);
	}
}