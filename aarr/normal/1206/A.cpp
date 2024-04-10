#include <iostream>
using namespace std;

const int N = 105;

int a[N];
int b[N];
bool mark[4 * N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mark[a[i]] = true;
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		mark[b[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!mark[a[i] + b[j]]) {
				cout << a[i] << " " << b[j];
				return 0;
			}
		}
	}
	return 0;
}