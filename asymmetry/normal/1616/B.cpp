//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int N = 101'000;
char s[N];

void pri(int x) {
	for (int i = 1; i <= x; ++i) {
		printf("%c", s[i]);
	}
	for (int i = x; i; --i) {
		printf("%c", s[i]);
	}
	printf("\n");
}

void solve() {
	int n;
	scanf("%d%s", &n, s + 1);
	if (n == 1) {
		pri(1);
		return;
	}
	if (s[1] <= s[2]) {
		pri(1);
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] < s[i + 1]) {
			pri(i);
			return;
		}
	}
	pri(n);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}