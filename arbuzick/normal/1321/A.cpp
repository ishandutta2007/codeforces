#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++)
		cin >> r[i];
	vector<int> b(n);
	int rr;
	rr = 0;
	int br;
	br = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 0 and r[i] == 1)
			rr += 1;
		if (b[i] == 1 and r[i] == 0)
			br += 1;
	}
	if (rr == 0)
		cout << -1;
	else
		cout << br / rr + 1;
	return 0;
}