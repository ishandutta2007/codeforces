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

	int cur = 2;
	for (int i = 1; i <= N; i++) {
		int t = i * (i + 1) * (i + 1);
		t -= (cur / i);
		cout << t << endl;
		cur = i * (i + 1);
	}





}