#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 55;

struct str {
	int id, r, c;
};

int N, K;
int mat[5][MAXN], nxt[5][MAXN];
vector <str> ans;
vector <pii> cyc, perm;

void go() {
	while (1) {
		bool has = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)
				if (mat[i][j])
					has = true;
		
		if (!has)		
			break;
			
		for (int i = 0; i < N; i++) {
			if (mat[0][i] == mat[1][i] && mat[0][i]) {
				ans.push_back({mat[0][i], 0, i});
				mat[0][i] = mat[1][i] = 0;
			}
			if (mat[3][i] == mat[2][i] && mat[3][i]) {
				ans.push_back({mat[3][i], 3, i});
				mat[3][i] = mat[2][i] = 0;
			}
		}
		
		pii pos = {-1, -1};
		for (int i = 1; i < 3; i++)
			for (int j = 0; j < N; j++)
				if (!mat[i][j]) 
					pos = {i, j};
				
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)
				nxt[i][j] = mat[i][j];
				
		int idx = -1;
		for (int i = 0; i < 2 * N; i++)
			if (cyc[i] == pos)
				idx = i;
		
		for (int i = 0; i < 2 * N; i++) {
			idx = (idx - 1 + 2 * N) % (2 * N);
			nxt[perm[idx].first][perm[idx].second] = mat[cyc[idx].first][cyc[idx].second];
			if (mat[cyc[idx].first][cyc[idx].second])
				ans.push_back({mat[cyc[idx].first][cyc[idx].second], perm[idx].first, perm[idx].second});
		}
		
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)
				mat[i][j] = nxt[i][j];
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", mat[i] + j);
	
	if (K == 2 * N) {
		for (int i = 0; i < N; i++) {
			if (mat[0][i] == mat[1][i]) {
				ans.push_back({mat[0][i], 0, i});
				mat[0][i] = mat[1][i] = 0;
				break;
			}
			if (mat[3][i] == mat[2][i]) {
				ans.push_back({mat[3][i], 3, i});
				mat[3][i] = mat[2][i] = 0;
				break;
			}
		}
		if (ans.empty()) {
			puts("-1");
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
		cyc.push_back({1, i});
	for (int i = N - 1; i >= 0; i--)
		cyc.push_back({2, i});
	
	perm.resize(2 * N);
	for (int i = 0; i < 2 * N; i++)
		perm[i] = cyc[(i + 1) % (2 * N)];
	
	go();
	
	assert(ans.size() <= 20000);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d %d\n", it.id, it.r + 1, it.c + 1);
		
	return 0;
}