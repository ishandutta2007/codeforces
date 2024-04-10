#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	int cnt = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '1') {
			cnt++;
		}
	}

	if (cnt % 2 == 1) {
		cnt++;
	}

	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i] == '1') {
			cnt--;
		}
	}

	if (cnt >= 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	//system("pause");
}