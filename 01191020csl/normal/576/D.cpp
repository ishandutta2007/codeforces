#include<bits/stdc++.h>
using namespace std;
struct matrix {
	bitset<151> bs[151];
};
int n;
matrix operator*(matrix a, matrix b) {
	matrix ans;
	bitset<151> tmp[151];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			tmp[j][i] = b.bs[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans.bs[i][j] = (a.bs[i] & tmp[j]).any();
	return ans;
}
matrix power(matrix a, int m) {
	matrix ans;
	for (int i = 1; i <= n; i++) ans.bs[i][i] = 1;
	while (m) {
		if (m & 1) ans = ans * a;
		a = a * a;
		m >>= 1;
	}
	return ans;
}
struct edge {
	int a, b, d;
}e[151];
bool operator<(const edge &a, const edge &b) {
	return a.d < b.d;
}
matrix eg;
int dis[151];
int getdis(bitset<151> ans) {
	queue<int> q;
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		if (ans[i]) q.push(i), dis[i] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
			if (eg.bs[u][i] && dis[i] > dis[u] + 1) {
				dis[i] = dis[u] + 1;
				q.push(i);
			}
	}
	return dis[n];
}
int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> e[i].a >> e[i].b >> e[i].d;
	sort(e + 1, e + m + 1);
	bitset<151> ans;
	ans[1] = 1;
	int res = getdis(ans), ld = 0;
	for (int i = 1; i <= m; i++) {
		matrix tmp = power(eg, e[i].d - ld);
		bitset<151> nxt;
		for (int j = 1; j <= n; j++)
			if (ans[j]) nxt |= tmp.bs[j];
		ans = nxt;
		eg.bs[e[i].a][e[i].b] = 1;
		res = min(res, e[i].d + getdis(ans));
		ld = e[i].d;
	}
	if (res == 0x3f3f3f3f) puts("Impossible");
	else cout << res << endl;
}