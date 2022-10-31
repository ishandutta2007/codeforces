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
	int N;
	cin >> N;
	int n1 = 0;
	int n2 = 0;
	int k;
	for (int i = 0; i < N; i++) {
		cin >> k;
		if (k == 1)n1++;
		else n2++;
	}

	vector<int> res;

	if (n2 > 0) {
		n2--;
		res.push_back(2);
	}
	if (n1 > 0) {
		n1--;
		res.push_back(1);
	}

	while (n2 > 0) {
		n2--;
		res.push_back(2);
	}

	while (n1 > 0) {
		n1--;
		res.push_back(1);
	}

	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;


}