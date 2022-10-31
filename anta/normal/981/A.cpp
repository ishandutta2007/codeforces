#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	string S;
	while (cin >> S) {
		int n = (int)S.size();
		int ans = 0;
		for (int i = 0; i < n; ++ i) for (int j = i + 1; j <= n; ++ j) {
			string t = S.substr(i, j - i);
			if (t != string(t.rbegin(), t.rend()))
				amax(ans, j - i);
		}
		printf("%d\n", ans);
	}
}