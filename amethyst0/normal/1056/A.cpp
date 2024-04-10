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
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

int main() {
	int n;

	cin >> n;

	map <int, int> s;

	for (int i = 0; i < n; i++) {
		int r;

		scanf("%d", &r);

		for (int j = 0; j < r; j++) {
			int x;

			scanf("%d", &x);

			s[x]++;
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		if (it->second == n) {
			printf("%d ", it->first);
		}
	}

	//system("pause");
}