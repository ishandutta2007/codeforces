#include<bits/stdc++.h>

using namespace std;

char s[300];
int cnt[3];
bool was[201][201][201];

void dfs(int x, int y, int z) {
	if (was[x][y][z]) return;
	was[x][y][z] = true;
	if (x + y + z == 1) return;
	
	if (x > 1) dfs(x - 1, y, z);
	if (y > 1) dfs(x, y - 1, z);
	if (z > 1) dfs(x, y, z - 1);
	
	if (x * y > 0) dfs(x - 1, y - 1, z + 1);
	if (x * z > 0) dfs(x - 1, y + 1, z - 1);
	if (y * z > 0) dfs(x + 1, y - 1, z - 1);
}

int main() {
	int n;
	scanf("%d %s", &n, s);
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') cnt[0]++;
		if (s[i] == 'G') cnt[1]++;
		if (s[i] == 'B') cnt[2]++;
	}
	
	dfs(cnt[0], cnt[1], cnt[2]);
	
	if (was[0][0][1]) printf("B");
	if (was[0][1][0]) printf("G");
	if (was[1][0][0]) printf("R");
	printf("\n");
	
	return 0;
}