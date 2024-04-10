#include <bits/stdc++.h>

using namespace std;

long long n, ret = 0; 
map <long long, long long> X, Y;
map <pair <long long, long long>, long long> XY;

int main() {
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++) {
		long long x, y;
		scanf("%I64d %I64d", &x, &y);
		X[x]++, Y[y]++;
		XY[make_pair(x, y)]++;
	}
	
	for (auto it : X) {
		long long m = it.second;
		ret += m * (m - 1)/2;
	}
	
	for (auto it : Y) {
		long long m = it.second;
		ret += m * (m - 1)/2;
	}
	
	for (auto it : XY) {
		long long m = it.second;
		ret -= m * (m - 1)/2;
	}
	
	cout << ret << endl;
	return 0;
}