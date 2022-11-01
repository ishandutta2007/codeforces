#include <bits/stdc++.h>

using namespace std;

int main() {
	string a[] = {"YES\n", "NO\n"};
	int w; cin >> w;
	if (w == 2) cout << a[1];
	else cout << a[w & 1];
	return 0;
}