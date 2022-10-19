#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 2e18;

int N, X, Y;
pii p[MAXN];
multiset <int> S;

void load() {
	scanf("%d%d%d", &N, &X, &Y);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
}

inline void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int solve() {	
	sort(p, p + N);
	
	int sol = 0;
	for (int i = 0; i < N; i++) {
		ll tmp = INF;
		add(sol, (ll)Y * (p[i].second - p[i].first) % MOD);
		if (!S.empty() && *S.begin() < p[i].first) 
			tmp = (ll)Y * (p[i].first - *(--S.lower_bound(p[i].first)));
		if (tmp < X) {
			S.erase(--S.lower_bound(p[i].first));
			add(sol, tmp % MOD);
		}
		else 
			add(sol, X);
		S.insert(p[i].second);
	}
	
	return sol;		
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}