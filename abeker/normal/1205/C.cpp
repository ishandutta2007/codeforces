#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 55;

struct edge {
	int a, b, w;
};

int N;
vector <edge> adj[MAXN][MAXN];
int clr[MAXN][MAXN];

int query(pii p1, pii p2) {
	printf("? %d %d %d %d\n", ++p1.first, ++p1.second, ++p2.first, ++p2.second);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

void ask2(int x1, int y1, int x2, int y2) {
	int tmp = query({x1, y1}, {x2, y2}) ^ 1;
	adj[x1][y1].push_back({x2, y2, tmp});
	adj[x2][y2].push_back({x1, y1, tmp});
}

void dfs(int x, int y, int c) {
	if (clr[x][y] != -1)
		return;
	clr[x][y] = c;
	for (auto it : adj[x][y])
		dfs(it.a, it.b, c ^ it.w);
}

int is_pal(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int go(pii curr, pii fin, int toggle, string s) {
	if (curr.first > fin.first || curr.second > fin.second)
		return 0;
	int tmp = clr[curr.first][curr.second];
	if ((curr.first + curr.second) % 2)
		tmp ^= toggle;
	s += (char)(tmp + '0');
	if (curr == fin)
		return is_pal(s);
	if (go({curr.first + 1, curr.second}, fin, toggle, s))
		return 1;
	if (go({curr.first, curr.second + 1}, fin, toggle, s))
		return 1;
	return 0;
}

int get_ans(pair <pii, pii> mv, int toggle) {
	return go(mv.first, mv.second, toggle, "");
}

void finish(pair <pii, pii> mv1, pair <pii, pii> mv2) {
	map <pii, int> which;
	for (int i = 0; i < 2; i++)
		which[{get_ans(mv1, i), get_ans(mv2, i)}] = i;
	
	if (which.size() == 1)
		return;
	
	int res = which[{query(mv1.first, mv1.second), query(mv2.first, mv2.second)}];
	
	puts("!");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2)
				clr[i][j] ^= res;
			printf("%d", clr[i][j]);
		}
		puts("");
	}
	exit(0);
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			ask2(i, j, i + 1, j + 1);
	
	ask2(0, 1, 2, 1);
	for (int i = 0; i < N - 2; i++) {
		ask2(0, i, 0, i + 2);
		ask2(i, 0, i + 2, 0);
	}
	
	memset(clr, -1, sizeof clr);	
	
	dfs(0, 0, 1);
	dfs(0, 1, 0);
	
	vector <pair <pii, pii>> moves;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = i; k < N; k++)
				for (int l = j; l < N; l++)
					if (k + l == i + j + 3)
						moves.push_back({{i, j}, {k, l}});
	
	for (auto it1 : moves)
		for (auto it2 : moves)
			finish(it1, it2);
			
	return 0;
}