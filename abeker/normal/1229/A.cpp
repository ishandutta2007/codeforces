#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 7e3 + 5;

int N;
vector <int> adj[MAXN];
ll a[MAXN];
int b[MAXN];
int indeg[MAXN];
bool bad[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

ll solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j && (a[i] & a[j]) == a[j]) {
				adj[i].push_back(j);
				indeg[j]++;
			}
	
	queue <int> Q;
	for (int i = 0; i < N; i++)
		if (!indeg[i])
			Q.push(i);
	
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		bad[x] = true;
		for (auto it : adj[x])
			if (--indeg[it] == 0) 
				Q.push(it);
	}
	
	int good = 0;
	ll sol = 0;
	for (int i = 0; i < N; i++)
		if (!bad[i]) {
			sol += b[i];
			good++;
		}
	
	return good >= 2 ? sol : 0;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}