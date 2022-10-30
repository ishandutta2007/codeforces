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
	int H, M, S, T1, T2;
	cin >> H >> M >> S >> T1 >> T2;
	M /= 5;
	S /= 5;
	if (S == 0)S = 12;
	if (M == 0)M = 12;
	bool f = false;
	bool f2 = true;
	for (int i = T1; i != T2;) {
	
		if (i == H || (i == M) || i == S) {
			f2 = false;
		}
		i++;
		if (i == 13) {
			i = 1;
		}
	}
	if (f2) {
		f = f2;
	}
	f2 = true;
	for (int i = T1; i != T2;) {
		i--;
		if (i == 0) {
			i = 12;
		}
		if (i == H || (i == M) || i == S) {
			f2 = false;
		}
		
	}
	if (f2) {
		f = f2;
	}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}