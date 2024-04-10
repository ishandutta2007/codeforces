#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int num = 0;
	while (isdigit(c)) {
		num = num * 10 + c - '0';
		c = getchar();
	}
	return num;
}
void write(long long num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
struct info {
	int b, c;
};
bool operator<(info a, info b) {
	return a.c < b.c;
}
vector<info> v[600];
long long f[600];
int vis[600], tmp[600];
void solve(int x, int n) {
	memset(f, 0x3f, sizeof(f));
	memset(vis, 0, sizeof(vis));
	f[x] = 0;
	for (int t = 0; t < n; t++) {
		int p = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && (p == -1 || f[i] < f[p])) p = i;
		vis[p] = 1;
		int q = 0, f0 = f[p] % n;
		queue<pair<int, int>> qu;
		memset(tmp, 0, sizeof(tmp));
		qu.push(make_pair((v[p][q].b+f0)%n, v[p][q].c)), tmp[(v[p][q].b+f0)%n] = 1;
		while (qu.size()) {
			pair<int, int> tp = qu.front();
			qu.pop(), f[tp.first] = min(f[tp.first], f[p]+tp.second);
			while (q < v[p].size() && v[p][q].c <= tp.second) {
				int val = v[p][q].b+f0>=n?v[p][q].b+f0-n:v[p][q].b+f0;
				if (!tmp[val]) qu.push(make_pair(val, v[p][q].c)), tmp[val] = 1;
				++q;
			}
			++tp.first, ++tp.second;
			if (tp.first == n) tp.first = 0;
			if (!tmp[tp.first]) tmp[tp.first] = 1, qu.push(tp);
		}
	}
	for (int i = 0; i < n; i++) write(f[i]), putchar(' ');
	putchar('\n');
}
int main() {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int a = read(), b = read(), c = read();
		info tmp;
		tmp.b = b, tmp.c = c;
		v[a].push_back(tmp);
	}
	for (int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
	for (int i = 0; i < n; i++) solve(i, n);
}