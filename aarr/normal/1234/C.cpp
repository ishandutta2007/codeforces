#include <iostream>
using namespace std;


const int N = 200 * 1000 + 5;
int n;
bool mark[N][3][3];
string s[3];
void dfs(int i, int j, int k) {
	if (i == n + 1) {
		mark[i][j][k] = true;
		return ;
	}
	if (mark[i][j][k] == true)
		return ;
	mark[i][j][k] = true;
//	cout << i << " " << j << " " << k << endl;
	if ((k == 0 && s[j][i - 1] < '3') || (k == 1 && s[j][i - 1] >= '3')) {
		dfs(i + 1, j, 0);
	}
	if (k == 0 && s[j][i - 1] >= '3') {
		dfs(i, 1 - j, 1);
	}
}
int main() {
	int q;
	cin >> q;
	for (int t = 0; t < q; t++) {
		cin >> n;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= 2; j++) {
				for (int k = 0; k <= 2; k++) {
					mark[i][j][k] = false;
				}
			}
		}
		cin >> s[0];
		cin >> s[1];
		dfs(1, 0, 0);
		if (mark[n + 1][1][0])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}