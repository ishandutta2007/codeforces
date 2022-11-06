#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {


	int n;
	cin >> n;

	ll ans = 0;
	
	map<int, int> mpX, mpY;
	map<pair<int, int>, int> mpXY;
	
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ans += mpX[x]++ + mpY[y]++ - mpXY[{x, y}]++;
	}

	cout << ans << endl;
	return 0;
}