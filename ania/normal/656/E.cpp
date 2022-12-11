#include <bits/stdc++.h>
using namespace std;

int n, res;
int t[22][22];

void rec_read(int i, int j) {
	j==n ? (j=0, i++) : 0;
	i==n ? 0 : (
		scanf("%d", &t[i][j]),
		rec_read(i,j+1),
		0
		);
}

void rec_calc(int k, int i, int j) {
	j==n ? (j=0, i++) : 0;
	i==n ? (i=0, k++) : 0;
	k==n ? 0 : (
		t[i][j] = min(t[i][j], t[i][k] + t[k][j]),
		rec_calc(k, i, j+1),
		0
	);
}

void rec_res(int i, int j) {
	j==n ? (j=0, i++) : 0;
	i==n ? 0 : (
		res = max(res, t[i][j]),
		rec_res(i,j+1),
		0
		);
}

int main() {
	scanf("%d", &n);
	rec_read(0,0);
	rec_calc(0,0,0);
	rec_res(0,0);
	printf("%d\n", res);
	return 0;
}