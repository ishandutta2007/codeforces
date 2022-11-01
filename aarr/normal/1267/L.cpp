#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int n, d, k, pnt = 1;
string t[N], s;
void solve(int l, int r, int y) {
	int x = l;
	while (y <= d) {
		if (x != l && s[pnt] != s[pnt - 1]) {
			solve(x, r, y);
			break;
		}
		t[x] += s[pnt];
	   	pnt++;
		x++;
		if (x == r + 1)
			y++, x = l;
			
	}
}

int main() {
	cin >> n >> d >> k;
	cin >> s;
	sort (s.begin(), s.end());
	s = s[0] + s;
	solve(1, k, 1);
	for (int i = 1; i <= n; i++) {
		while (t[i].size() < d) {
			t[i] += s[pnt];
			pnt++;
		}
		cout << t[i] << endl;
	}
	return 0;
}