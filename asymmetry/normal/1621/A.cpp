//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

char s[100][100];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			s[i][j] = '.';
		}
	}
	for (int i = 1; i <= n; i += 2) {
		if (!k) {
			break;
		}
		s[i][i] = 'R';
		--k;
	}
	if (k) {
		printf("-1\n");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}