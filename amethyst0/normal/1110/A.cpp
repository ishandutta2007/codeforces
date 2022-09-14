#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;

int main() {
	int b, k;

	cin >> b >> k;

	int total = 0;

	for (int i = 0; i < k; i++) {
		int x;

		scanf("%d", &x);

		if (i != k - 1) {
			if (b & 1) {
				total += x;
				total &= 1;
			}
		}
		else {
			total += x;
			total &= 1;
		}
	}

	if (total) {
		cout << "odd" << endl;
	}
	else {
		cout << "even" << endl;
	}

	//system("pause");

	return 0;
}