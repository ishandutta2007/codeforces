#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long
#define ld long double

const int maxn = (int)7010;

ll a[maxn];
int b[maxn];
bool used[maxn];

int main() {
	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	ll res = 0;

	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {
				cnt++;
			}
		}

		if (cnt > 1) {
			for (int j = 0; j < n; j++) {
				if ((a[i] & a[j]) == a[j]) {
					used[j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (used[i]) {
			res += b[i];
		}
	}

	cout << res << endl;

	//system("pause");
}