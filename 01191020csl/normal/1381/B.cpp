#include<bits/stdc++.h>
using namespace std;
int p[4001], f[4001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n * 2; i++) cin >> p[i];
		for (int i = 0; i <= n; i++) f[i] = 0;
		f[0] = 1;
		int x = 1;
		while (x <= n * 2) {
			int y = x;
			while (y <= n * 2 && p[y] <= p[x]) ++y;
			for (int i = n; i >= y - x; i--) f[i] |= f[i-(y-x)];
			x = y;
		}
		if (f[n]) puts("YES");
		else puts("NO");
	}
}