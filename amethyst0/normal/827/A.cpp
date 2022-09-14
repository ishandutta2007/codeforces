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
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define uint unsigned int
#define pb push_back
#define sz(a) (int)(a.size())

using namespace std;

const int maxn = (int)2e6 + 10;

char s[maxn];
int lnk[maxn], pre[maxn];
char ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < maxn; i++) {
		lnk[i] = i + 1;
		pre[i] = i - 1;
	}

	int d = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int len = strlen(s);

		int k;

		scanf("%d", &k);

		for (int j = 0; j < k; j++) {
			int pos;

			scanf("%d", &pos);

			pos--;

			int w = pos;

			while (w - pos < len) {
				ans[w] = s[w - pos];
				d = max(d, w);

				if (pre[w] != -1) {
					lnk[pre[w]] = lnk[w];
				}

				if (lnk[w] != maxn) {
					pre[lnk[w]] = pre[w];
				}
				
				int f = w;

				w = lnk[w];
				
				lnk[f] = max(lnk[f], min(maxn, pos + len));
			}
		}
	}

	for (int i = 0; i < d; i++) {
		if (ans[i] == 0) {
			ans[i] = 'a';
		}
	}

	printf("%s", ans);

	return 0;
}