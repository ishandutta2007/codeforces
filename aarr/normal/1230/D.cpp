#include <iostream>
using namespace std;

const int N = 7005;

long long a[N];
int b[N];
bool adj[N][N];
int outdeg[N];
bool mark[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		mark[i] = true;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((a[i] & ~a[j])> 0) {
				adj[i][j] = true;
				outdeg[i]++;
			}
			else
				adj[i][j] = false;
	//		cout << adj[i][j] << " ";
		//	cout << i << " " << j << " " << (a[i] & ~a[j]) << endl;
		}
	//	cout << endl;
	}
	int left = n;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i <= n; i++) {
			if (outdeg[i] == left - 1) {
				flag = true;
				left--;
				mark[i] = false;
				for (int j = 1; j <= n; j++) {
					if (adj[j][i]) {
						outdeg[j]--;
					}
				}
			}
		}
	}

	if (left < 2) {
		cout << 0 << endl;
	}
	else {
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (mark[i])
	//			cout << i << endl;
				ans += b[i];
		}
		cout << ans << endl;
	}
	return 0;
}