/*input
7
1 2 4 6 5 3 7

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	int maxHill = 0, cntMax = 0, hilltop = -1;

	for (int i = n - 2, curHill = 0; i >= 0; --i) {
		curHill = (p[i] > p[i + 1]) ? curHill + 1 : 0;
		if (curHill > maxHill) {
			maxHill = curHill, cntMax = 1, hilltop = i;
		} else if (curHill == maxHill) {
			++cntMax, hilltop = (hilltop == i) ? i : -1;
		}
	}

	for (int i = 1, curHill = 0; i < n; ++i) {
		curHill = (p[i] > p[i - 1]) ? curHill + 1 : 0;
		if (curHill > maxHill) {
			maxHill = curHill, cntMax = 1, hilltop = i;
		} else if (curHill == maxHill) {
			++cntMax, hilltop = (hilltop == i) ? i : -1;
		}
	}

	cout << (!(maxHill & 1) && cntMax == 2 && ~hilltop) << endl;
}