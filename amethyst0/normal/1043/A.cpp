#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = 110;
int a[maxn];

int main() {
	int n;
	cin >> n;
	
	int k = 0;
	
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		k = max(k, a[i]);
	}
	
	for (int i = k; ; i++) {
		if ((ll)n * i - sum > sum) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}