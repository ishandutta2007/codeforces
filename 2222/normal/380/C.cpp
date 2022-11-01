#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

char s[1 << 20];

struct query { int i, x, y; };

int f[1 << 21];

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
    gets(s);
	int m;
	scanf("%d", &m);
	vector<query> q(m);
	REP (i, m) {
		q[i].i = i;
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x;
		--q[i].y;
	}
	sort(all(q), [](const query &p, const query &q) { return p.y < q.y; });
	vector<int> st;
	int i = 0;
	for (auto &t : q) {
		for (; i <= t.y; ++i) {
			if (s[i] == '(') {
				st.pb(i);
			} else if (sz(st)) {
				for (int x = st.back() + (1 << 20); x; x /= 2)
					f[x] += 2;
				st.pop_back();
			}
		}
		int sum = 0;
		for (int x = t.x + (1 << 20), y = (1 << 21) - 1; x <= y; x = (x + 1) / 2, y = (y - 1) / 2) {
			if (x & 1) sum += f[x];
			if (~y & 1) sum += f[y];
		}
		t.x = sum;
	}
	sort(all(q), [](const query &p, const query &q) { return p.i < q.i; });
	for (auto &t : q)
		printf("%d\n", t.x);
    return 0;
}