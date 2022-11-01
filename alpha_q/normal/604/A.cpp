#include <bits/stdc++.h>

using namespace std;

int main() {
	int m[6], w[6], hs, hu;
	int s[] = {0, 500, 1000, 1500, 2000, 2500};
	for (int i = 1; i <= 5; i++) cin >> m[i];
	for (int i = 1; i <= 5; i++) cin >> w[i];
	cin >> hs >> hu;
	
	double ret = 0;
	for (int i = 1; i <= 5; i++) 
		ret += max(0.3 * s[i], (1.0 - m[i]/250.0) * s[i] - 50.0 * w[i]);
	ret += hs * 100 - hu * 50;
	cout << ret << endl;
	return 0;
}