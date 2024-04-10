#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

const long long MAXI = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
vector<long long> lucky;

int main() {	
	long long x, y, l, r;
	cin >> x >> y >> l >> r;
	
	long long p1 = 1;
	while(true) {
		long long p2 = 1;
		while(true) {
			lucky.push_back(p1 + p2);
			if(p2 <= MAXI / y) p2 *= y; else break;
		}
		if(p1 <= MAXI / x) p1 *= x; else break;
	}
	
	sort(lucky.begin(), lucky.end());
	
	int iLucky = 0;
	while(iLucky < (int)lucky.size() && lucky[iLucky] < l) {
		iLucky++;
	}
	
	long long maxInt = lucky[iLucky] - l;
	
	iLucky++;;
	
	while(iLucky < (int)lucky.size() && lucky[iLucky] <= r) {
		maxInt = max(maxInt, lucky[iLucky] - lucky[iLucky - 1] - 1);
		iLucky++;
	}
	
	maxInt = max(maxInt, r - lucky[iLucky - 1]);
	
	cout << min(maxInt, r - l + 1) << endl;
	return 0;
}