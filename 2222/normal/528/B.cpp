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

int main() {
    int n;
	scanf("%d", &n);
	vector<pii> q;
	REP (i, n) {
		int x, w;
		scanf("%d%d", &x, &w);
		q.pb(pii(x + w, x - w));
	}
	sort(all(q));
	int res = 0;
	int r = -2000000001;
	for (auto p : q) {
		if (p.Y >= r) {
			++res;
			r = p.X;
		}
	}
	cout << res << endl;
    return 0;
}