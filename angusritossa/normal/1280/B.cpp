#include <bits/stdc++.h>
using namespace std;
int grid[100][100], colisgood[100], rowisgood[100], allisgood, allisbad;
int r, c, t;
void solve() {
	scanf("%d%d", &r, &c);
	allisgood = 1;
	allisbad = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char a;
			scanf(" %c", &a);
			if (a == 'A') grid[i][j] = 1, allisbad = 0;
			else grid[i][j] = 0, allisgood = 0;
		}
	}
	for (int i = 0; i < r; i++) {
		rowisgood[i] = 1;
		for (int j = 0; j < c; j++) {
			if (!grid[i][j]) rowisgood[i] = 0;
		}
	}
	for (int j = 0; j < c; j++) {
		colisgood[j] = 1;
		for (int i = 0; i < r; i++) {
			if (!grid[i][j]) colisgood[j] = 0;
		}
	}
	if (allisgood) {
		printf("%d\n", 0);
		return;
	}
	if (rowisgood[0] || rowisgood[r-1] || colisgood[0] || colisgood[c-1]) {
		printf("1\n");
		return;
	}
	if (accumulate(rowisgood, rowisgood+r, 0) || accumulate(colisgood, colisgood+c, 0) || grid[0][0] || grid[0][c-1] || grid[r-1][0] || grid[r-1][c-1]) {
		printf("2\n");
		return;
	}
	int isOneOnBorder = 0;
	for (int i = 0; i < r; i++) {
		if (grid[i][0] || grid[i][c-1]) isOneOnBorder = 1;
	}
	for (int i = 0; i < c; i++) {
		if (grid[0][i] || grid[r-1][i]) isOneOnBorder = 1;
	}
	if (isOneOnBorder) {
		printf("3\n");
		return;
	}
	if (!allisbad) {
		printf("4\n");
	} else {
		printf("MORTAL\n");
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) solve();
}