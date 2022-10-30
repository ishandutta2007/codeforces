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
	string S;
	cin >> S;
	string T = S;
	for (int i = 0; i < (int)S.size(); i++) {
		T.push_back(S[(int)S.size() - 1 - i]);
	}
	cout << T << endl;
}