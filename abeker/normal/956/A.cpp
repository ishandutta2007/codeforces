#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N, M;
char mat[MAXN][MAXN];
vector <int> E[MAXN];
bool bio[MAXN];
int rows, cols, edges;

void dfs(int x) {
	bio[x] = true;
	if (x < N)
		rows++;
	else
		cols++;
	edges += E[x].size();
	for (auto it : E[x])
		if (!bio[it])
			dfs(it);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] == '#') {
				E[i].push_back(N + j);
				E[N + j].push_back(i);
			}
			
	bool ok = true;
	for (int i = 0; i < N + M; i++)
		if (!bio[i]) {
			rows = cols = edges = 0;
			dfs(i);	
			ok &= edges == 2 * rows * cols;
		}
		
	puts(ok ? "Yes" : "No");
			
	return 0;
}