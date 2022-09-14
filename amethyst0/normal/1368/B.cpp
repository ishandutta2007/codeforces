#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

string s;

int main() {
	s = "codeforces";

	ll k;

	cin >> k;

	int x = 1;

	while (true) {
		ll cur = 1;

		for (int i = 0; i < 10; i++) {
			cur *= x;
			if (cur >= k) {
				break;
			}
		}

		if (cur >= k) {
			break;
		}
		else {
			x++;
		}
	}

	int cnt = 0;

	while (true) {
		ll cur = 1;

		for (int i = 0; i < cnt; i++) {
			cur *= x;
			if (cur >= k) {
				break;
			}
		}

		for (int i = 0; i < 10 - cnt; i++) {
			cur *= x - 1;
			if (cur >= k) {
				break;
			}
		}

		if (cur >= k) {
			break;
		}

		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < x; j++) {
			printf("%c", s[i]);
		}
	}

	for (int i = cnt; i < 10; i++) {
		for (int j = 0; j < x - 1; j++) {
			printf("%c", s[i]);
		}
	}
}