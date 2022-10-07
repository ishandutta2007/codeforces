#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int MAXN = 1 << 18;
const int INF = 1e9;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, q;
int p[MAXN];
int cnt[MAXN];

int get(int x) {
	if (x == p[x]) return x;
	return p[x] = get(p[x]);
}

void uni(int u, int v) {
	u = get(u);
	v = get(v);
	if (u == v) return;
	if (cnt[u] < cnt[v]) swap(u, v);
	p[v] = u;
	cnt[u] += cnt[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &q);
	set<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		cnt[i] = 1;
		st.insert(make_pair(i, i));
	}

	for (int it = 0; it < q; it++) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		--x; --y;
		if (t == 1) {
			set<pair<int, int> > :: iterator it;
			it = st.lower_bound(make_pair(x + 1, x + 1));
			it--;
			pair<int, int> o1 = *it;
			it = st.lower_bound(make_pair(y + 1, y + 1));
			it--;
			pair<int, int> o2 = *it;
			uni(o1.first, o2.first);
		}
		if (t == 2) {
			set<pair<int, int> > :: iterator it;
			it = st.lower_bound(make_pair(x + 1, x + 1));
			it--;

			vector<pair<int, int> > vct;
			while (it != st.end() && it->first <= y) {
				uni(x, it->first);
				vct.push_back(*it);
				it++;
			}
			for (int i = 0; i < (int)vct.size(); i++) {
				st.erase(vct[i]);
			}
			st.insert(make_pair(vct[0].first, vct.back().second));
		}
		if (t == 3) {
			x = get(x);
			y = get(y);
			if (x == y) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}