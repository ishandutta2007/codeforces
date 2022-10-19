#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N;
vector <int> adj[MAXN], ind[MAXN];
char s[MAXN];
int dp[250][2];
int pot[10];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		adj[i].clear();
		ind[i].clear();
	}
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%s", s + 1);
}

int rec(int mask, int who) {
	int &ref = dp[mask][who];
	if (ref != -1)
		return ref;
		
	vector <int> num(N + 1, 0);
	int copy = mask;
	for (int i = 1; i <= N; i++) {
		num[i] = copy % 3;
		copy /= 3;
	}
	
	for (int i = 1; i <= N; i++)
		if (num[i] != 2) {
			int same = 0;
			for (auto it : adj[i])
				same += num[it] == num[i];
			if (same >= 2)
				return ref = (who == num[i]);
		}
		
	bool draw = false, term = true;
	for (int i = 1; i <= N; i++) 
		if (num[i] == 2) {
			int nxt = rec(mask + (who - 2) * pot[i - 1], who ^ 1);
			if (!nxt)
				return ref = 1;
			if (nxt == 2)
				draw = true;	
			term = false;
		}
	
	if (draw || term)
		return ref = 2;
	return ref = 0;
}

bool solve_small() {
	memset(dp, -1, sizeof dp);
	
	pot[0] = 1;
	for (int i = 1; i <= N; i++)
		pot[i] = 3 * pot[i - 1];
	
	int state = 0;
	for (int i = 0; i < N; i++) 
		state += pot[i] * (s[i + 1] == 'W' ? 1 : 2);
	
	return rec(state, 1) % 2;
}

bool solve() {
	if (N <= 5)
		return solve_small();
	
	vector <int> un, white;
	for (int i = 1; i <= N; i++)
		if (s[i] == 'N')
			un.push_back(i);
		else 
			white.push_back(i);
	
	for (auto it : un) {
		for (auto nxt : adj[it])
			if (s[nxt] == 'N')
				ind[it].push_back(nxt);
		if (ind[it].size() > 3)
			return true;
	}
	
	int three = 0;
	for (auto it : un)
		if (ind[it].size() == 3) {
			int leaves = 0;
			for (auto nxt : ind[it])
				leaves += adj[nxt].size() == 1;
			if (leaves != 2)
				return true;
			three++;
		}
		
	for (auto it : white)
		if (adj[it].size() > 1 || adj[adj[it][0]].size() > 2)
			return true;
	
	if (three > 1)
		return N % 2;
		
	if (white.size() == 2)
		return N % 2;
	
	if (white.size() == 1 && three)
		return !(N % 2);
		
	return false;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		puts(solve() ? "White" : "Draw");
	}
	return 0;
}