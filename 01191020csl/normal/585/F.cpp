#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int ch[500001][10], dep[500001], cnt;
char s[1005], x[55], y[55];
void insert(int l, int r, int d) {
	int p = 0;
	for (int i = l; i <= r && i <= l + d/2 - 1; i++) {
		int c = s[i] - '0';
		if (!ch[p][c]) ch[p][c] = ++cnt, dep[cnt] = dep[p] + 1;
		p = ch[p][c];
	}
}
int fa[500001], vis[500001];
void build() {
	queue<int> q;
	for (int i = 0; i < 10; i++)
		if (ch[0][i]) q.push(ch[0][i]);
	while (q.size()) {
		int u = q.front();
		vis[u] = 1, q.pop();
		for (int i = 0; i < 10; i++)
			if (!ch[u][i]) ch[u][i] = ch[fa[u]][i];
			else fa[ch[u][i]] = ch[fa[u]][i], q.push(ch[u][i]);
	}
}
int f[51][500001][2];
int getans(char s[], int d) {
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1;
	for (int i = 0; i < d; i++)
		for (int j = 0; j <= cnt; j++) {
			for (int k = 0; k < s[i+1] - '0'; k++)
				if (dep[ch[j][k]] < d/2) f[i+1][ch[j][k]][1] = (f[i+1][ch[j][k]][1] + f[i][j][0]) % mod;
			if (dep[ch[j][s[i+1]-'0']] < d/2) f[i+1][ch[j][s[i+1]-'0']][0] = (f[i+1][ch[j][s[i+1]-'0']][0] + f[i][j][0]) % mod;
			for (int k = 0; k < 10; k++)
				if (dep[ch[j][k]] < d/2) f[i+1][ch[j][k]][1] = (f[i+1][ch[j][k]][1] + f[i][j][1]) % mod;
		}
	int ans = 1;
	for (int i = 1; i <= d; i++) ans = (10ll * ans + s[i] - '0') % mod;
	for (int i = 0; i <= cnt; i++) {
		assert(dep[i] < d/2 || (!f[d][i][0] && !f[d][i][1]));
		ans = (mod + ans - f[d][i][0]) % mod, ans = (mod + ans - f[d][i][1]) % mod;
	}
	return ans;
}
int main() {
	cin >> s + 1 >> x + 1 >> y + 1;
	int n = strlen(s + 1), d = strlen(x + 1);
	for (int i = 1; i <= n; i++) insert(i, n, d);
	build();
	for (int i = d; i >= 1; i--)
		if (x[i] == '0') x[i] = '9';
		else {
			--x[i];
			break;
		}
	cout << (mod + getans(y, d) - getans(x, d)) % mod << endl;
}