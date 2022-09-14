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
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int get_day(string s) {
	if (s[0] == 'm') {
		return 0;
	} else if (s[0] == 't' && s[1] == 'u') {
		return 1;
	} else if (s[0] == 'w') {
		return 2;
	} else if (s[0] == 't' && s[1] == 'h') {
		return 3;
	} else if (s[0] == 'f') {
		return 4;
	} else if (s[0] == 's' && s[1] == 'a') {
		return 5;
	}

	return 6;
}

int main() {
	string a, b;

	cin >> a >> b;

	int x = get_day(a), y = get_day(b);

	if (x == y) {
		cout << "YES" << endl;
	} else if ((x + 2) % 7 == y) {
		cout << "YES" << endl;
	} else if ((x + 3) % 7 == y) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}