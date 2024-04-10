#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 200010
typedef long long ll;
map<ll, ll> toAdd[2], toPrefix[2], val;
set<ll> important;
ll x[MAXN], p[MAXN];
bool bad[MAXN];
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		int n;
		ll m;
		toAdd[0].clear();
		toAdd[1].clear();
		toPrefix[0].clear();
		toPrefix[1].clear();
		val.clear();
		important.clear();
		scanf("%d%lld", &n, &m);
		for (int i = 0; i < n; i++) {
			bad[i] = false;
			scanf("%lld%lld", &x[i], &p[i]);
			toAdd[0][x[i]] += p[i];
			toPrefix[0][x[i]]--;
			ll e = x[i]+p[i];
			important.insert(e);
			toPrefix[0][e]++;

			toAdd[1][x[i]] += p[i];
			toPrefix[1][x[i]]--;
			e = x[i]-p[i];
			important.insert(e);
			toPrefix[1][e]++;
			
			important.insert(x[i]);
		}
		vector<ll> import;
		for (auto a : important) {
			import.push_back(a);
		}
		ll v = 0, P = 0, pre = 0;
		for (auto i : import) {
			v += (i-pre)*P + toAdd[0][i];
			P += toPrefix[0][i];
			val[i] = v;
			pre = i;
		}
		v = P = 0;
		reverse(import.begin(), import.end());
		for (auto i : import) {
			v += (pre-i)*P;
			P += toPrefix[1][i];
			val[i] += v;
			v += toAdd[1][i];
			pre = i;
		}

		reverse(import.begin(), import.end());
		priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;

		for (auto i : import) {
			D("%lld: %lld\n", i, val[i]);
		}

		for (int i = 0; i < n; i++) {
			pq.push({p[i]-x[i], i});
		}

		for (auto i : import) {
			while (pq.size() && x[pq.top().second] < i) pq.pop();
			if (val[i] > m) {
				while (pq.size() && val[i] - pq.top().first - i > m) {
					D("%lld is bad due to %lld (%lld)\n", pq.top().second, i, pq.top().first);
					bad[pq.top().second] = true;
					pq.pop();
				}

			}
		}

		reverse(import.begin(), import.end());
		while (pq.size()) pq.pop();
		for (int i = 0; i < n; i++) {
			pq.push({p[i]+x[i], i});
		}

		for (auto i : import) {
			while (pq.size() && x[pq.top().second] > i) pq.pop();
			if (val[i] > m) {
				while (pq.size() && val[i] - pq.top().first + i > m) {
					bad[pq.top().second] = true;
					pq.pop();
				}

			}
		}

		for (int i = 0; i < n; i++) {
			if (bad[i]) printf("0");
			else printf("1");
		}
		printf("\n");
	}

}