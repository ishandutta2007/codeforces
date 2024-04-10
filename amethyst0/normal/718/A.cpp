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

using namespace std;

#define ll long long
#define mp make_pair

const int maxn = (int)2e5 + 10;
char s[maxn];
int n, t;
int pos;

void add(int w, int t) {
	if (t == 0 || w < 0 || s[w] < '5' || w < pos) {
		if (w == -1) {
			cout << '1';
		}

		for (int i = 0; i <= w; i++) {
			printf("%c", s[i]);
		}

		if (w < pos) {
			for (int i = w + 1; i < pos; i++) {
				printf("%c", s[i]);
			}
		}

		return;
	}

	t--;
	w--;

	while (w > pos && s[w] == '9') {
		s[w] = '0';
		w--;
	}

	bool st = false;

	if (w == pos) {
		st = true;
		w--;
	}

	while (st && w >= 0 && s[w] == '9') {
		s[w] = '0';
		w--;
	}

	if (w != -1) {
		s[w]++;
	}

	add(w, t);
}

int main() {
	cin >> n >> t;

	scanf("%s", s);

	pos = n;

	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			pos = i;
			break;
		}
	}

	int cnt = 0;
	int w = n - 1;

	for (int i = pos + 1; i < n && t > 0; i++) {
		if (s[i] >= '5') {
			add(i, t);
			return 0;
		}
	}

	printf("%s", s);

	return 0;
}