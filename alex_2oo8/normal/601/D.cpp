#include<bits/stdc++.h>

#define next ololo

using namespace std;

const int MX = 500000;

vector<int> E[MX];
int c[MX], sz[MX], root[MX], maxVal = -1, maxCnt;
map<char, int> next[6000000];
char s[MX];

int newNode() {
	static int tw = -1;
	
	return ++tw;
}

int add(int v, int u) {
	int res = 0;
	for (auto iter = next[u].begin(); iter != next[u].end(); iter++) {
		if (next[v].count(iter->first) == 0) {
			next[v][iter->first] = newNode();
			
			res++;
		}
		
		res += add(next[v][iter->first], iter->second);
	}
	
	return res;
}

void dfs(int v, int par = -1) {
	int mxChild = -1;
	for (int u : E[v])
		if (u != par) {
			dfs(u, v);
			
			if (mxChild == -1 || sz[u] > sz[mxChild]) mxChild = u;
		}
	
	root[v] = newNode();
	if (mxChild == -1) {
		sz[v] = 1;
		next[root[v]][s[v]] = newNode();
	}
	else {
		sz[v] = sz[mxChild] + 1;
		next[root[v]][s[v]] = root[mxChild];
		
		for (int u : E[v])
			if (u != par && u != mxChild)
				sz[v] += add(next[root[v]][s[v]], root[u]);
	}
	
	if (sz[v] + c[v] > maxVal) {
		maxVal = sz[v] + c[v];
		maxCnt = 1;
	}
	else if (sz[v] + c[v] == maxVal)
		maxCnt++;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", c + i);
	scanf("%s", s);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		u--;
		v--;
		
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	dfs(0);
	
	printf("%d %d\n", maxVal, maxCnt);
	
	return 0;
}