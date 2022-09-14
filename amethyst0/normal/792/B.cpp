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
vector <int> now;

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++) {
		now.push_back(i);
	}

	int pos = 0;
	int it = 0;

	while (it != k) {
		pos += v[it];
		it++;

		pos %= (int)now.size();

		printf("%d ", now[pos] + 1);

		int pp = pos;

		while (pos != (int)now.size() - 1) {
			swap(now[pos], now[pos + 1]);
			pos++;
		}

		now.pop_back();
		if (!now.empty()) {
			pos = pp % (int)now.size();
		}
	}

	return 0;
}