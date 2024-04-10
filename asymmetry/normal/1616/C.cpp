//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

void solve() {
	int n;
	scanf("%d", &n);
	vector <int> t(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
	}
	if (n < 3) {
		printf("0\n");
		return;
	}
	int odp = 1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int ans = 0;
			double r = (double)(t[i] - t[j]) / (i - j);
			for (int k = i; k < n; ++k) {
				if (abs(t[k] - (t[i] + r * (k - i))) > 1e-6) {
					++ans;
				}
			}
			for (int k = 0; k < i; ++k) {
				if (abs(t[k] - (t[i] - r * (i - k))) > 1e-6) {
					++ans;
				}
			}
			odp = min(odp, ans);
		}
	}
	printf("%d\n", odp);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}