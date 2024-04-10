#include<bits/stdc++.h>
using namespace std;

int cntCmp;
bool check[200005];
int numb[200005], cnt[200005], nx[200005];

void dfs(int u) {
	check[u] = 1;
	numb[u] = cntCmp;
	int v = nx[u];
	if (!check[v]) dfs(v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			check[i] = 0;
			cnt[i] = 0;
			cin >> nx[i];
		}
		cntCmp = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				cntCmp++;
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			cnt[numb[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			cout << cnt[numb[i]] << ' ';
		}
		cout << '\n';
	}
	return 0;
}