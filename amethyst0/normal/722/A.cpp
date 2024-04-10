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
	int tp;

	cin >> tp;

	int x, y;

	scanf("%d:%d", &x, &y);

	if (y >= 60) {
		y %= 10;
	}

	if (tp == 12) {
		if (x == 0) {
			x = 10;
		} else if (x > 12) {
			while (x > 12) {
				x -= 10;
			}
		}
	} else if (x > 23) {
		while (x > 23) {
			x -= 10;
		}
	}

	printf("%.2d:%.2d", x, y);

	return 0;
}