#include <iostream>
using namespace std;


const int N = 105;
bool a[N], b[N];
char c[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*') {
				a[i] = true;
				b[j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] && b[j] && c[i][j] == '.') {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}