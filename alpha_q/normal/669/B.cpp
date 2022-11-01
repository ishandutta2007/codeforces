#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n, d[100005]; cin >> n;
	int lim = 2 * n + 1;
	char s[100005]; scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", d + i);

	int pos = 1;
	while (lim--) {
		if (s[pos] == '>') pos = pos + d[pos];
		else pos = pos - d[pos];

		if (pos < 1 or pos > n) break;
	}

	if (lim == -1) cout << "INFINITE\n";
	else cout << "FINITE\n";
	return 0;
}