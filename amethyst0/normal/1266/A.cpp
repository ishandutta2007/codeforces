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

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;

		int sum = 0;

		for (int j = 0; j < (int)s.size(); j++) {
			sum += s[j] - '0';
		}

		if (sum % 3 != 0) {
			cout << "cyan\n";
			continue;
		}

		bool ok = false;

		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = 0; j < (int)s.size(); j++) {
				if (i == j) {
					continue;
				}

				int x = s[i] - '0';
				x *= 10;
				x += s[j] - '0';

				if (x % 20 == 0) {
					ok = true;
				}
			}
		}

		if (ok) {
			cout << "red\n";
		}
		else {
			cout << "cyan\n";
		}
	}

	//system("pause");
}