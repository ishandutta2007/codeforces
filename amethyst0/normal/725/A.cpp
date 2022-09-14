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
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)2e5 + 10;
char s[maxn];

int main() {
	int n;

	cin >> n;

	scanf("%s", s);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] != '<') {
			break;
		}

		ans++;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != '>') {
			break;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}