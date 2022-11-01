#include<bits/stdc++.h>
using namespace std;
int a[100001], c[100001], prv[100001];
int f[100001], g[100001];
int main() {
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != a[tot]) a[++tot] = x;
	}
	for (int i = 1; i <= tot; i++) {
		if (c[a[i]]) {
			int prv = c[a[i]];
			f[i] = max(f[prv+1], g[prv])+1;
		}
		g[i] = max(g[i-1], f[i]);
		c[a[i]] = i;
	}
	cout << tot - g[tot] << endl;
}