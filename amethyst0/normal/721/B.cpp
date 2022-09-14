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

const int maxn = 110;
string s;
int v[maxn];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;

		v[i] = (int)s.size();
	}

	string h;
	cin >> h;

	int len;

	len = (int)h.size();

	sort(v, v + n);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (i != 0 && i % k == 0) {
			cnt += 5;
		}

		cnt++;

		if (v[i] == len) {
			cout << cnt << ' ';
			break;
		}
	}

	cnt = 0;

	for (int i = 0; i < n; i++) {
		if (i != 0 && i % k == 0) {
			cnt += 5;
		}

		cnt++;

		if (v[i] == len && (i + 1 == n || v[i + 1] != v[i])) {
			cout << cnt << ' ';
			break;
		}
	}

	return 0;
}