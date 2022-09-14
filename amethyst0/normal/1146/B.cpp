#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

void bad() {
	cout << ":(" << endl;
	//system("pause");
	exit(0);
}

int main() {
	string s;

	cin >> s;

	int cnt = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'a') {
			cnt++;
		}
	}

	cnt = (int)s.size() - cnt;

	if (cnt % 2 == 1) {
		bad();
	}

	cnt /= 2;

	string res = "";

	int it = 0;
	for (int i = (int)s.size() - cnt; i < (int)s.size(); i++) {
		while (s[it] == 'a') {
			it++;
		}

		if (s[i] != s[it]) {
			bad();
		}

		it++;
	}

	for (int i = 0; i < (int)s.size() - cnt; i++) {
		res.push_back(s[i]);
	}

	cout << res << endl;
	
	//system("pause");

	return 0;
}