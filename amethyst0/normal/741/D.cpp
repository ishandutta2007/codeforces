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
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int MAXMEM = (int)2e8;
int curmem = 0;
char membuf[MAXMEM];
void* operator new(size_t n)
{
	void *p = membuf + curmem;
	curmem += n;
	return p;
}
void operator delete(void *) { }


const int maxn = (int)5e5 + 10;
vector <pair <int, char> > ed[maxn];
int h[maxn];
int sz[maxn];

inline int dfs(int v, int p, int hh = 0) {
	h[v] = hh;
	sz[v] = 1;
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != p) {
			sz[v] += dfs(u, v, hh + 1);
		}
	}

	return sz[v];
}

int ans[maxn];

inline int make(int v, int p) {
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != p) {
			ans[v] = max(ans[v], make(u, v));
		}
	}

	return ans[v];
}

unordered_map <int, int> s[maxn];
int xorr[maxn];
int pos = 0;

inline void upd(int it, int v, int mask, int z) {
	auto i = s[it].find(mask);

	if (i != s[it].end()) {
		ans[v] = max(ans[v], i->second + z);
	}
}

inline void add(int it, int mask, int z) {
	s[it][mask] = max(s[it][mask], z);
}

inline int go(int v, int p, int num = 0) {
	int it = pos;
	xorr[pos] = 0;
	s[pos][0] = h[v];
	pos++;
	int sumsz = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u == p) {
			continue;
		}

		int nit = go(u, v, ed[v][i].second - 'a');

		//if (s[it].size() < s[nit].size()) {
		if (sumsz < sz[u]) {
			swap(it, nit);
		}
		
		sumsz += sz[u];

		for (auto j = s[nit].begin(); j != s[nit].end(); j++) {
			int mask = j->first;
			int d = j->second;
			mask ^= xorr[nit];
			mask ^= xorr[it];

			upd(it, v, mask, d - (h[v] << 1));

			for (int k = 0; k < 22; k++) {
				upd(it, v, mask ^ (1 << k), d - (h[v] << 1));
			}
		}
		
		auto j = s[nit].begin();

		while (j != s[nit].end()) {
			int mask = j->first;
			int d = j->second;
			mask ^= xorr[nit];
			mask ^= xorr[it];

			add(it, mask, d);

			j++;
		}

		//s[nit].clear();
	}

	xorr[it] ^= (1 << (num));
	return it;
}

bool cmp(pair <int, char> a, pair <int, char> b) {
    return sz[a.first] < sz[b.first];
}

int main() {
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;
		char x;

		scanf("%d %c", &p, &x);
		//p = i / 2;
		//x = 'a' + rand() % 22;

		ed[p].push_back(mp(i, x));
		ed[i].push_back(mp(p, x));
	}
	
    for (int i = 1; i <= n; i++) {
        sort(ed[i].begin(), ed[i].end(), cmp);
    }

	dfs(1, 1);

	go(1, 1);

	make(1, 1);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}