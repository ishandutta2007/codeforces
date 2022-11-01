#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 5;

int a[N];
vector <int> c[N];
int inc[N];
int ans[N];
bool mark[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int v = i, t = 0;
		if (mark[v])
			continue;
		while (!mark[v]) {
			mark[v] = true;
			t++;
			v = a[v];
		//	cout << "73 " << i << " " << v << endl;
		}
		c[t].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
	//	cout << i << " " << c[i].size() << endl;
		if (i % 2 == 0 && c[i].size() % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
		if (i % 2 == 0) {
			for (int j = 0; j < c[i].size(); j += 2) {
				int v = c[i][j], u = c[i][j + 1];
				int x = v, y = u;
				for (int k = 0; k < i; k++) {
					ans[x] = y;
					x = a[x];
					ans[y] = x;
					y = a[y];
				}
			}
		}
		else {
			for (int j = 0; j < c[i].size(); j++) {
				int v = c[i][j];
				int x = v, k = 0;
				for (int k = 0; k < i; k++) {
					inc[k] = x;
					x = a[x];
				}
			//	cout << "73 " << endl;
				int y = 0;
				while (ans[inc[y]] == 0) {
			//		cout << "49 " << 0 << endl;
					int z = (y + i / 2 + 1);
					z %= i;
					ans[inc[y]] = inc[z];
					y = z;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}