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
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

int main() {
	int n;

	cin >> n;

	string s;

	cin >> s;

	vector <int> f;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			if (cnt != 0) {
				f.push_back(cnt);
			}
			cnt = 0;
		} else {
			cnt++;
		}
	}

	if (cnt != 0) {
		f.push_back(cnt);
	}

	cout << f.size() << endl;

	for (int i = 0; i < (int)f.size(); i++) {
		printf("%d ", f[i]);
	}

	return 0;
}