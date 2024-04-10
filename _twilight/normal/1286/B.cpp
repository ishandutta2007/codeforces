#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2005;

typedef vector<int> vec;

vec operator + (vec a, vec b) {
	for (auto x : b)
		a.push_back(x);
	return a;
}

int n, rt;
int c[N];
vector<int> G[N];

vec dfs(int p) {
	vec rt;
	for (auto e : G[p])
		rt = rt + dfs(e);
	if (!(c[p] <= (signed) rt.size())) {
		puts("NO");
		exit(0);
	}
	rt.insert(rt.begin() + c[p], p);
	return rt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, fa; i <= n; i++) {
		scanf("%d%d", &fa, c + i);
		if (fa) {
			G[fa].push_back(i);
		} else {
			rt = i;
		}
	}
	vec p = dfs(rt);
	for (int i = 0; i < n; i++)
		c[p[i]] = i + 1;
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", c[i]);
	return 0;
}