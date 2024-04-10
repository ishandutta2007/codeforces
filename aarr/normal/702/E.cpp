#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, LG = 40;


int nxt[N][LG];
int mn[N][LG];
long long s[N][LG];
int get(long long x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i][0];
	} 
	for (int i = 0; i < n; i++) {
		cin >> s[i][0];
		mn[i][0] = s[i][0];
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 0; i < n; i++) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			mn[i][j] = min(mn[i][j - 1], mn[nxt[i][j - 1]][j - 1]);
			s[i][j] = s[i][j - 1] + s[nxt[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		int v = i, ans2 = mn[i][0];
		long long ans1 = 0;
		for (int j = 0; j < LG; j++) {
			if (get(k, j)) {
				ans1 += s[v][j];
				ans2 = min(ans2, mn[v][j]);
				v = nxt[v][j];
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}