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

const int M = 100500;

int n, m;

vector<int> a;
vector< pair<ll, int> > b;
vector< pair<ll, int> > s;

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
	cin >> m;
	ll pos = 0;
	REP (i, m) {
		int t, l, c;
		cin >> t >> l;
		if (t == 1) {
			if (sz(a) < M) {
				a.push_back(l);
			} else {
				b.push_back({pos, l});
			}
			++pos;
		} else {
			assert(t == 2);
			cin >> c;
			for (; c > 0 && sz(a) < M; --c) {
				vector<int> r(a.begin(), a.begin() + l);
				a.insert(a.end(), all(r));
				pos += l;
			}
			if (c > 0) {
				s.push_back({pos, l});
				pos += l * c;
			}
		}
	}
	cin >> n;
	REP (i, n) {
		if (i) putchar(' ');
		ll x;
		cin >> x;
		--x;
		if (x < sz(a)) {
			cout << a[x];
		} else {
			auto i = lower_bound(all(b), make_pair(x, 0));
			if (i != b.end() && i->X == x)
				cout << i->Y;
			else {
				i = lower_bound(all(s), make_pair(x + 1, 0)) - 1;
				cout << a[(x - i->X) % i->Y];
			}
		}
	}
	cout << endl;
    return 0;
}