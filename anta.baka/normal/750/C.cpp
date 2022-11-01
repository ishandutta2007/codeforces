#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int d = 0;
	int lo = INT_MIN;
	int hi = INT_MAX;
	int c, div;
	cin >> d >> div;
	if(div == 1)
		lo = 1900;
	else
		hi = 1899;
	for(int i = 1; i < n; i++) {
		cin >> c >> div;
		if(div == 1)
			lo = max(lo, 1900 - d);
		else
			hi = min(hi, 1899 - d);
		d += c;
	}
	if(hi == INT_MAX)
		cout << "Infinity";
	else if(lo > hi)
		cout << "Impossible";
	else
		cout << hi + d;
}