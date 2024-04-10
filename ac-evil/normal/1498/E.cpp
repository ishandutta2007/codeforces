#include <bits/stdc++.h>
using std::vector; using std::sort;
const int N = 505;
int n, k[N], vis[N];
int qry(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	static char s[4];
	scanf("%s", s);
	return s[0] == 'Y';
}
struct node { int x, y; };
bool cmp(node a, node b) { return k[a.x] - k[a.y] > k[b.x] - k[b.y]; }
vector<node> v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			v.push_back(k[i] < k[j] ? (node){j, i} : (node){i, j});
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		if (qry(v[i].x, v[i].y)) {
			printf("! %d %d\n", v[i].x, v[i].y);
			return 0;
		}
	puts("! 0 0");
	return 0;
}