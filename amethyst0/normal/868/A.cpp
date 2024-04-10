/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

string t[110];

int main() {
	string s;

	cin >> s;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i];

		if (s == t[i]) {
			cout << "YES\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (t[i][1] == s[0] && t[j][0] == s[1]) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}