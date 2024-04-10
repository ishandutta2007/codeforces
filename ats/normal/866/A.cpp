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
	if (N != 1) {
		cout << (N - 1) * 2 << " " << 2 << endl;
		cout << 1 << " " << 2 << endl;
	}
	else {
		cout << 1 << " " << 1 << endl;
		cout << 1 << endl;
	}
}