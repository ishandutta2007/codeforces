#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if(x > y) {
		swap(x, y);
	}
	
	vector<int> cotes(3, x);
	int nbChangements = 0;
	while(cotes[0] != y) {
		cotes[0] = min(y, cotes[1] + cotes[2] - 1);
		nbChangements++;
		sort(cotes.begin(), cotes.end());
	}
	cout << nbChangements << endl;
	return 0;
}