/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	int dst = (int)2e9 + 1;
	int cnt = 0;

	for (int i = 0; i < n - 1; i++) {
		int d = v[i + 1] - v[i];

		if (d < dst) {
			dst = d;
			cnt = 1;
		} else if (d == dst) {
			cnt++;
		}
	}

	cout << dst << ' ' << cnt << endl;

	return 0;
}