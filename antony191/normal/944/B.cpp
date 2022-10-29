#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <bitset>


using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	sort(x.begin(), x.end());
	int st = x.front();
	int cn[3] = { 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		cn[x[i] - st]++;
	}
	if (cn[2] != 0)
	if (min(cn[0], cn[2]) > (cn[1] / 2)) {
		int k = min(cn[0], cn[2]);
		cn[0] -= k;
		cn[2] -= k;
		cn[1] += 2 * k;
		n -= 2 * k;
	}
	else {
		int k = cn[1] / 2;
		cn[0] += k;
		cn[2] += k;
		cn[1] -= 2 * k;
		n -= 2 * k;
	}
	printf("%d\n", n);
	for (int i = 0; i < cn[0]; ++i)
		printf("%d ", st);
	for (int i = 0; i < cn[1]; ++i)
		printf("%d ", st + 1);
	for (int i = 0; i < cn[2]; ++i)
		printf("%d ", st + 2);
	return 0;
}