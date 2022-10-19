#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
char mat[MAXN][MAXN];
char s[MAXN];
int dir[5];

bool check() {
	int x = -1, y = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] == 'S') {
				x = i;
				y = j;
			}
		
	for (int i = 0; s[i]; i++) {
		x += dx[dir[s[i] - '0']];
		y += dy[dir[s[i] - '0']];
		if (x < 0 || y < 0 || x >= N || y >= M)
			return false;
		if (mat[x][y] == '#')
			return false;
		if (mat[x][y] == 'E')
			return true;
	}
	
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	scanf("%s", s);
	
	for (int i = 0; i < 4; i++)
		dir[i] = i;
	
	int sol = 0;
	do 
		sol += check();
	while (next_permutation(dir, dir + 4));
	
	printf("%d\n", sol);
	
	return 0;
}