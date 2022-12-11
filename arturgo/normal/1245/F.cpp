#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

bitset<30> x, y;

int curTest = 0;
int derTest[30][2][2][2];
long long dyn[30][2][2][2];

long long nbSols(int a, bool down, bool up, int colle) {
	if(a == -1) {
		return 1;
	}

	if(derTest[a][down][up][colle] == curTest)
		return dyn[a][down][up][colle];
	derTest[a][down][up][colle] = curTest;

	long long ans = 0;

	//0 0
	if(!down || x[a] == 0) {
		ans += nbSols(a - 1, down, up && y[a] == 0, colle);
	}

	//0 1
	if((!down || x[a] == 0) && (!up || y[a] == 1)) {
		ans += nbSols(a - 1, down && x[a] == 0, up && y[a] == 1, false);
	}

	//1 0
	if(!colle) {
		ans += nbSols(a - 1, down && x[a] == 1, up && y[a] == 0, false);
	}

	return dyn[a][down][up][colle] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbTests;
	cin >> nbTests;

	for(int iTest = 0;iTest < nbTests;iTest++) {
		int left, right;
		cin >> left >> right;

		curTest = iTest + 1;

		x = bitset<30>(left);
		y = bitset<30>(right);

		cout << 2 * nbSols(29, true, true, true) - (left == 0) << endl;
	}
	return 0;
}