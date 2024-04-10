#include<bits/stdc++.h>
using namespace std;
int ch[10000001][2], cnt;
void insert(int x) {
	int p = 0;
	for (int i = 29; i >= 0; i--) {
		int c = (x>>i) & 1;
		if (!ch[p][c]) ch[p][c] = ++cnt;
		p = ch[p][c];
	}
}
int dfs(int x) {
	if (!ch[x][0] && !ch[x][1]) return 1;
	if (!ch[x][0]) return dfs(ch[x][1]);
	if (!ch[x][1]) return dfs(ch[x][0]);
	return max(dfs(ch[x][0]), dfs(ch[x][1])) + 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		insert(a);
	}
	cout << n - dfs(0) << endl;
}