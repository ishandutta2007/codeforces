#include <bits/stdc++.h> 

using namespace std;

int c, v0, v1, a, l;

int main() {
	cin >> c >> v0 >> v1 >> a >> l;
	c -= v0;
	v0 += a;
	v0 = min(v0, v1);
	int tot = 1;
	for (int i = 1; c > 0; ++i) {
		c -= (v0 - l);
		++tot;
		v0 += a;
		v0 = min(v0, v1);
	}
	cout << tot << endl;
  return 0;
}