#include <bits/stdc++.h>
using namespace std;
int main() {
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int res = 0;
	int p = 0;
	while (p < c) {
		if (res > 0) {
			p -= l;
		}
		p += min(v1, v0 + (a*res));
		res++;
	}
	cout << res << endl;
	return 0;
	
}