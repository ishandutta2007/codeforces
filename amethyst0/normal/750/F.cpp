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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1 << 7;

vector <int> ed[maxn];
vector <int> now;
bool used[maxn];

int cnt = 0;
int lasth = -1;

void del(int x) {
	while (!ed[x].empty() && used[ed[x].back()]) {
		ed[x].pop_back();
	}
}

bool read(int x) {
	cnt++;

	if (cnt > 16) {
		cout << "! " << x << endl;
		return true;
	}

	printf("? %d\n", x);
	fflush(stdout);
	ed[x].clear();
	now.push_back(x);
	used[x] = true;
	int k;

	scanf("%d", &k);

	if (k == 0) {
		exit(0);
	}

	ed[x].resize(k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &ed[x][i]);
	}

	random_shuffle(ed[x].begin(), ed[x].end());

	if (k == 2) {
		printf("! %d\n", x);
		fflush(stdout);
		return true;
	}

	return false;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		lasth = -1;
		cnt = 0;
		memset(used, 0, sizeof used);
		now.clear();
		int h;

		cin >> h;

		if (h == 0) {
			exit(0);
		}

		int n = (1 << h) - 1;

		if (read(rand() % n + 1)) {
			continue;
		}

		while (true) {
			int x = now.back();

			del(x);

			if (!ed[x].empty()) {
				int y = ed[x].back();
				ed[x].pop_back();

				if (read(y)) {
					break;
				}
			} else {
				reverse(now.begin(), now.end());

				int x = now.back();

				if (!ed[x].empty()) {
					continue;
				}

				int sz = (int)now.size();

				for (int i = 0; i < sz / 2; i++) {
					now.pop_back();
				}

				lasth = now.size();

				if (lasth == 5 && h == 7) {
					x = now.back();

					while (!ed[x].empty() && used[ed[x].back()]) {
						ed[x].pop_back();
					}

					if (ed[x].empty()) {
						throw 1;
					}

					x = ed[x].back();

					read(x);

					vector <int> a;

					while (!ed[x].empty()) {
						if (used[ed[x].back()]) {
							
						} else {
							a.push_back(ed[x].back());
						}

						ed[x].pop_back();
					}

					if (read(a[0])) {
						break;
					}

					if (read(a[1])) {
						break;
					}

					throw 1;
				} else if (lasth == 4 && h == 7) {
					x = now.back();

					while (!ed[x].empty() && used[ed[x].back()]) {
						ed[x].pop_back();
					}

					if (ed[x].empty()) {
						throw 1;
					}

					x = ed[x].back();

					read(x);

					vector <int> a;

					while (!ed[x].empty()) {
						if (used[ed[x].back()]) {
							
						} else {
							a.push_back(ed[x].back());
						}

						ed[x].pop_back();
					}

					read(a[0]);
					read(a[1]);

					vector <int> b;

					for (int i = 0; i < 2; i++) {
						x = a[i];

						while (!ed[x].empty()) {
							if (used[ed[x].back()]) {

							} else {
								b.push_back(ed[x].back());
							}

							ed[x].pop_back();
						}
					}

					while (!b.empty()) {
						if (read(b.back())) {
							break;
						}

						b.pop_back();
					}

					break;
				}
			}
		}
	}

	return 0;
}