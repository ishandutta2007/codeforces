#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXP = 2e6 + 5;
const int MOD = 1e9 + 7;

int N;
int p[MAXP];
int cnt[MAXP];
vector <int> adj[MAXP];
vector < vector <pii> > all;
int mx1[MAXP], mx2[MAXP];

void load() {
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void add(int x) {
	vector <pii> f;
	while (x > 1) {
		int t = p[x], ex = 0;
		for (; !(x % t); x /= t)
			ex++;
		if (ex >= mx1[t]) {
			mx2[t] = mx1[t];
			mx1[t] = ex;
		}
		else if (ex > mx2[t])
			mx2[t] = ex;
		f.push_back({t, ex});
	}
	all.push_back(f);
}

void dfs(int x) {
	cnt[x] = 0;
	add(x - 1);
	for (auto it : adj[x])
		if (cnt[it])
			dfs(it);
}

int solve() {
	for (int i = 2; i < MAXP; i++)	
		if (!p[i])
			for (int j = i; j < MAXP; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = 2; i < MAXP; i++)
	 	if (cnt[i])
			for (int j = i + 1; j < MAXP; j += i)
				if (cnt[j])
					adj[j].push_back(i);
		
	bool ok = false;
	for (int i = MAXP - 1; i; i--)
		if (cnt[i]) {
			add(i);
			ok |= cnt[i] > 2;
			if (cnt[i] > 1) 
				dfs(i);
		}
		
	for (auto it : all) {
		bool tmp = true;
		for (auto curr : it)
			tmp &= mx2[curr.first] >= curr.second;
		ok |= tmp;
	}
		
	int sol = 1;
	for (int i = 1; i < MAXP; i++)
		while (mx1[i]--)
			sol = mul(sol, i);
	
	return (sol + ok) % MOD;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}