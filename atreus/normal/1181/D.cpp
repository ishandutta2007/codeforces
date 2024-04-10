#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 5e5 + 10;

int fen[maxn], m, a[maxn], ans[maxn];

void add(int idx){
	idx ++;
	for (; idx <= m; idx += idx & -idx)
		fen[idx] ++;
}

int get(int p){
	int now = 0;
	for (int i = 19; i >= 0; i--){
		if (now + (1 << i) > m)
			continue;
		if (fen[now + (1 << i)] < p){
			p -= fen[now + (1 << i)];
			now += (1 << i);
		}
	}
	return now + 1;
}

int main(){
//	ios_base::sync_with_stdio(false);
	int n, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++){
		int v;
		scanf("%d", &v);
		v --;
		a[v] ++;
	}
	vector<pair<ll, int> > cities;
	for (int i = 0; i < m; i++)
		cities.push_back({a[i], i});
	sort(cities.begin(), cities.end());
	vector<pair<ll, int> > Q;
	for (int i = 0; i < q; i++){
		ll k;
		scanf("%lld", &k);
		k -= n;
		Q.push_back({k, i});
	}
	sort(Q.begin(), Q.end(), greater<pair<ll, int> >());
	ll now = 0;
	for (int i = 0; i < m; i++){
		add(cities[i].second);
		ll T;
		if (i == m - 1)
			T = (long long)1e18 + 10;
		else
			T = 1ll * (i + 1) * (cities[i + 1].first - cities[i].first);
		while (!Q.empty() and now + T >= Q.back().first){
			ll t = Q.back().first - now;
			ll p = t % (i + 1);
			if (p == 0)
				p = (i + 1);
			ans[Q.back().second] = get(p);
			Q.pop_back();
		}
		now += T;
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}