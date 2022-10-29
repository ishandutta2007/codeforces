#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int A[4][4] = {
	{8, 9, 1, 13},
	{3, 12, 7, 5},
	{0, 2, 4, 11},
	{6, 10, 15, 14}
};

int n;
int a[1024][1024];

int main() {
	scanf("%d", &n);
	int dlt = 0;
	for (int i = 0; i < n; i += 4) {
		for (int j = 0; j < n; j += 4) {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					a[i + x][j + y] = A[x][y] + dlt;
				}
			}
			dlt += 16;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}