#include<bits/stdc++.h>
using namespace std;
int prv[200001], nxt[200001];
int id[200001], p[100001], ans[200001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n * 2; i++) {
		char c;
		cin >> c;
		if (c == '-') {
			id[i] = 1;
			int x;
			cin >> x;
			p[x] = i;
		}
	}
	for (int i = 1; i <= n * 2; i++) prv[i] = i-1, nxt[i] = i+1;
	for (int i = 1; i <= n; i++) {
		if (!prv[p[i]] || id[prv[p[i]]]) {
			puts("NO");
			return 0;
		}
		ans[prv[p[i]]] = i;
		if (prv[prv[p[i]]]) nxt[prv[prv[p[i]]]] = nxt[p[i]];
		if (nxt[p[i]]) prv[nxt[p[i]]] = prv[prv[p[i]]];
	}
	puts("YES");
	for (int i = 1; i <= n * 2; i++)
		if (ans[i]) cout << ans[i] << ' ';
	cout << endl;
}