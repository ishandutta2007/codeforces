//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 510;

int main() {
	int n, m;

	cin >> n >> m;

	if (n == 1) {
		if (m == 1) {
			cout << 0 << endl;
		}
		else {
			for (int i = 2; i <= m + 1; i++) {
				cout << i << ' ';
			}
		}
	}
	else {
		if (m == 1) {
			for (int i = 2; i <= n + 1; i++) {
				cout << i << '\n';
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = n + 1; j <= n + m; j++) {
					cout << i * j << ' ';
				}

				cout << '\n';
			}
		}
	}

	//system("pause");
}