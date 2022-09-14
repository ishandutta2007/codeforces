#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 200010;

int a[maxn]; //  .

int n, k;

int get_number(int l) {
	//  ,  ,     l  n - 1

	int ans = 1;
	int sz = k;

	for (int i = l; i < n; i++) {
		if (a[i] <= sz) {
			sz -= a[i];
		}
		else {
			ans += 1;
			sz = k;
			sz -= a[i];
		}
	}

	return ans;
}

int main() {
	int m;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//O(n ^ 2);

	int l = 1; //   
	int r = n + 1; //    

	while (l + 1 != r) {
		//     1.(l , r  ),     l,   r = l + 1.
		//  = r - l;
		int mid = (l + r) / 2;

		if (get_number(n - mid) <= m) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	cout << l << endl;

	//system("pause");

	return 0;
}

//   .
//   k ,     k - 1.
//   pos  n - 1,      pos + 1  n - 1.
//     pos  n - 1,       pos - 1  n - 1.
//     ,    .
//   0(   ),    1,     .