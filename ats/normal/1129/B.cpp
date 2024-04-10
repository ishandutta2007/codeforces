#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	vector<int> res;
	res.push_back(0);
	res.push_back(-1);

	int x;
	
	for (x = 1;; x++) {
		if ((k + x) % 2 == 1)continue;

		int s = (k + x + 2) / 2;
		if ((s + x - 1) / x <= 1000000 - 3){
			break;
		}
	}

	int sum = (k + x + 2) / 2;
	int ss = sum;
	//cerr << x << " "  << sum << endl;
	while(x > 0) {
		int t = ss / x;
		ss -= t;
		res.push_back(t);
		x--;
	}
	//int mx = 0;
	//for (int i = 0; i < res.size(); i++)mx = max(mx, res[i]);
	//cerr << mx << endl;
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0) cout << " ";
		cout << res[i];
	}
	cout << endl;
}