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

int doit(set<int> &xs, multiset<int> &dxs, int x) {
	auto i = xs.insert(x).first;
	int a = *i - *prev(i);
	int b = *next(i) - *i;
	dxs.erase(dxs.find(a + b));
	dxs.insert(a);
	dxs.insert(b);
	return *dxs.rbegin();
}

int main() {
    int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	multiset<int> dxs, dys;
	set<int> hs, vs;
	hs.insert(0);
	hs.insert(h);
	vs.insert(0);
	vs.insert(w);
	dxs.insert(w);
	dys.insert(h);
	int maxX = w;
	int maxY = h;
	REP (i, n) {
		char tmp[3];
		int x;
		scanf("%s%d", tmp, &x);
		switch (*tmp) {
			case 'V':
				maxX = doit(vs, dxs, x);
				break;
			case 'H':
				maxY = doit(hs, dys, x);
				break;
		}
		cout << (ll)maxX * maxY << endl;
	}
    return 0;
}