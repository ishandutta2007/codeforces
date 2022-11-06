#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long lint;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<lint> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	lint s = 0;
	for (int i = 0; i < n; i++) {
		s += (i + 1) * a[i] - i;
	}
	cout << s;
	
	
	
	return 0;
}//erdkcl