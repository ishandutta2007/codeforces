#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0, n, m;
bool adj[10][10];
bool mark[8][8];
vector <int> vec;

int chck() {
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= i; j++) {
			mark[i][j] = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j]) {
				mark[max(vec[i], vec[j])][min(vec[i], vec[j])] = true;
			}
		}
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= i; j++) {
			if (mark[i][j])
				ans++;
		}
	}
	return ans;
}
void bt() {
	if (vec.size() == n + 1) {
		ans = max(ans, chck());
//		cout << chck() << endl;
		return;
	}
	for (int i = 1; i <= 6; i++) {
		vec.push_back(i);
		bt();
		vec.pop_back();
	}
}
int main() {
	vec.push_back(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
	}
	bt();
	cout << ans << endl;
	return 0;
}