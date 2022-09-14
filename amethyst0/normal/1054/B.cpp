#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int maxn = (int)1e5 + 10;

int a[maxn];

int main() {
	int n;

	scanf("%d", &n);

	int mex = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		if (a[i] > mex) {
			cout << i + 1 << endl;
			exit(0);
		}

		if (a[i] == mex) {
			mex++;
		}
	}

	cout << -1 << endl;

	//system("pause");
}