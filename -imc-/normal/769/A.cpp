#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += nxt();
	}
	cout << s / n << "\n";

	return 0;
}