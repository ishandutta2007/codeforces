#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int parent[MAXN];
vector <int> lvl[MAXN];
ll S;

void load() {
	scanf("%d%lld", &N, &S);
}

void no() {
	puts("No");
	exit(0);
}

void yes() {
	puts("Yes");
	for (int i = 2; i <= N; i++)
		printf("%d ", parent[i]);
	puts("");
	exit(0);
}

ll calc(int dep, int val, int rest) {
	return (ll)val * dep + (ll)rest * (2 * dep + rest + 1) / 2; 
}

void construct(int k) {
	int id = 0;
	ll tot = N, curr = 1;
	lvl[0].push_back(0);
	for (int d = 1; tot; d++) {
		ll lo = 0, hi = min(tot, curr);
		while (lo < hi) {
			ll mid = (lo + hi + 1) / 2;
			if (calc(d, mid, tot - mid) >= S)
				lo = mid;
			else
				hi = mid - 1;
		}
		
		for (int i = 0; i < lo; i++) {
			parent[++id] = lvl[d - 1][i / k];
			lvl[d].push_back(id);
		}
		
		tot -= lo;
		S -= lo * d; 
		curr = lo * k;
	}
}

bool check(int k) {
	ll sum = 0, pot = 1, tot = N;
	for (int d = 1; tot; d++) {
		ll tmp = min(pot, tot);
		sum += tmp * d;
		tot -= tmp;
		pot *= k;
	}
	return S >= sum;
}

void solve() {
	ll chain = (ll)N * (N + 1) / 2;
	int star = 2 * N - 1;
	if (S > chain || S < star)
		no();
	if (S == chain) {
		for (int i = 2; i <= N; i++)
			parent[i] = i - 1;
		yes();
	}
	
	int lo = 2, hi = N - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	construct(lo);
	
	yes();
}

int main() {
	load();
	solve();
	return 0;
}