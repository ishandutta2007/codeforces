#include <iostream>
#include <algorithm>

using namespace std;

int w[10][10];
char x[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf(" %c", &x[i][j]);
	}
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (x[i][j] == 'W') {
		for (int t = 0; t < 4; t++) {
		    if (i + dx[t] > -1 && j + dy[t] > -1 && i + dx[t] < n && j + dy[t] < m && x[i + dx[t]][j + dy[t]] == 'P') {
			x[i + dx[t]][j + dy[t]] = '-';
			ans++;
			break;
		    }
		}
	    }
	}
    }
    printf("%d\n", ans);
}