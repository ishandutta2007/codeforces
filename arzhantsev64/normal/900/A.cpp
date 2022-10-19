#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int pl = 0;
	int mn = 0;
	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x > 0)
			pl++;
		else
			mn++;
	}
	if (pl <= 1 || mn <= 1)
		cout << "Yes";
	else
		cout << "No";
}