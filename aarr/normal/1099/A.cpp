#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

int main() {
	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	a[d1] = u1;
	a[d2] += u2;
	for (int i = h; i > 0; i--) {
		w += i;
		w = max(w - a[i], 0);
	}
	cout << w;
	
	return 0;
}