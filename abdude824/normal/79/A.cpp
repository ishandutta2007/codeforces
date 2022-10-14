#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x, y;
	cin >> x >> y;
	int winner = 0;
	vector < pair < int, int > > a[2];
	a[0].push_back(make_pair(2, 2));
	a[0].push_back(make_pair(1, 12));
	a[0].push_back(make_pair(0, 22));

	a[1] = a[0];
	reverse(a[1].begin(), a[1].end());
	while (true) {
		bool can = false;
		for (int i = 0; i < a[winner].size(); ++i) {
			int p = a[winner][i].first;
			int q = a[winner][i].second;
			if (x >= p && y >= q) {
				x -= p;
				y -= q;
				can = true;
				break;
			}
		}
		if (!can) {
			if (winner == 0) {
				printf("Hanako\n");
			} else {
				printf("Ciel\n");
			}
			return 0;
		}
		winner = 1 - winner;
	}

	return 0;
}