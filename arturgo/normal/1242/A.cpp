#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

vector<int> diviseurs(int n) {
	vector<int> divs;
	for(int i = 1;i * i <= n;i++) {
		if(n % i == 0) {
			divs.push_back(i);
			if(i * i != n)
				divs.push_back(n / i);
		}
	}
	return divs;
}

signed main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	if(n <= 3) {
		cout << n << endl;
		return 0;
	}

	vector<int> divs = diviseurs(n);

	sort(divs.begin(), divs.end());

	int d = divs[1];
	int curDiv = d;
	for(int iDiv = 2;iDiv < (int)divs.size();iDiv++) {
		curDiv *= d;
		if(curDiv != divs[iDiv]) {
			cout << 1 << endl;
			return 0;
		}
	}

	cout << d << endl;
	return 0;
}