#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int perm[2][MAXN];
vector <int> sol[MAXN];
vector <int> v;
int mat[5][5];
bool adj[15][15];

void build() {
	int idx = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			mat[i][j] = v[idx++];
}

void check() {
	build();
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (j < M - 1 && adj[mat[i][j]][mat[i][j + 1]])
				return;
			if (i < N - 1 && adj[mat[i][j]][mat[i + 1][j]])
				return; 
		}
	
	puts("YES");
	for (int i = 0; i < N; i++, puts(""))
		for (int j = 0; j < M; j++)
			printf("%d ", mat[i][j]);
			
	exit(0);
}

void brute() {
	for (int i = 1; i <= N * M; i++)
		v.push_back(i);
	
	build();
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (j < M - 1)
				adj[mat[i][j]][mat[i][j + 1]] = true;
			if (i < N - 1)
				adj[mat[i][j]][mat[i + 1][j]] = true;
		}
	
	for (int i = 1; i <= N * M; i++)
		for (int j = 1; j <= N * M; j++)
			if (adj[i][j])
				adj[j][i] = true;
	
	do
		check(); 
	while (next_permutation(v.begin(), v.end()));
	
	puts("NO");
}

void solve_cols() {
	swap(N, M);
	for (int j = 0; j < M; j++) {
		vector <int> tmp;
		for (int i = 0; i < N; i++)
			tmp.push_back(sol[i][j]);
		for (int i = 0; i < N; i++)
			sol[i][j] = tmp[perm[j % 2][i + 1] - 1];
	}
}

void solve_rows() {
	for (int i = 0; i < N; i++) {
		vector <int> tmp = sol[i];
		for (int j = 0; j < M; j++)
			sol[i][j] = tmp[perm[i % 2][j + 1] - 1];
	}
}

int main() {
	scanf("%d%d", &N, &M);
	
	if (N <= 3 && M <= 3) {
		brute();
		return 0;
	}
	
	puts("YES");
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			sol[i].push_back(i * M + j + 1);
			
	bool f = false;
	if (N > M) {
		swap(N, M);
		f = true;
	}
	
	for (int i = 1; i <= M / 2; i++)
		perm[0][i] = 2 * i;
	
	for (int i = M / 2 + 1; i <= M; i++)
		perm[0][i] = 2 * (i - M / 2) - 1;
	
	for (int i = 1; i <= M; i++)
		perm[1][i] = perm[0][i];
		
	if (!(M % 2)) 
		reverse(perm[1] + 1, perm[1] + M + 1);
	else {
		rotate(perm[1] + 1, perm[1] + M / 2, perm[1] + M / 2 + 1);
		rotate(perm[1] + M / 2 + 1, perm[1] + M, perm[1] + M + 1);
	}
	
	if (f)	
		solve_cols();
	else
		solve_rows();
		
	for (int i = 0; i < N; i++, puts(""))
		for (int j = 0; j < M; j++)
			printf("%d ", sol[i][j]);
	
	return 0;
}