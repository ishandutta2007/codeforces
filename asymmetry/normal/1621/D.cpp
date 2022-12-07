//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int N = 600;
int nn;
int t[N][N];

void solve() {
	int n;
	scanf("%d", &n);
	nn = n * 2;
	long long wyn = 0;
	for (int i = 1; i <= nn; ++i) {
		for (int j = 1; j <= nn; ++j) {
			scanf("%d", &t[i][j]);
			if (i > n && j > n) {
				wyn += t[i][j];
				t[i][j] = 0;
			}
		}
	}
	int odp = 1e9;
	odp = min(odp, t[1][n + 1]);
	odp = min(odp, t[1][nn]);
	odp = min(odp, t[n][n + 1]);
	odp = min(odp, t[n][nn]);
	odp = min(odp, t[n + 1][1]);
	odp = min(odp, t[n + 1][n]);
	odp = min(odp, t[nn][1]);
	odp = min(odp, t[nn][n]);
	printf("%lld\n", wyn + odp);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}