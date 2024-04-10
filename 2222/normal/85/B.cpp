#include <algorithm>
#include <iostream>
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
typedef pair <ll, ll> pii;

int t1, t2, t3;
int k1, k2, k3, n;
pii c[100500];

void solve(int k, int t) {
	multiset<ll> S;
	REP (i, n) {
		if (S.size() < k) {
			c[i].X += t;
			S.insert(c[i].X);
		} else {
			auto l = S.begin();
			c[i].X = max(c[i].X, *l);
			S.erase(l);
			c[i].X += t;
			S.insert(c[i].X);
		}
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> k1 >> k2 >> k3;
	cin >> t1 >> t2 >> t3;
	scanf("%d", &n);
	REP (i, n) {
		int x;
		scanf("%d", &x);
		c[i] = {x, x};
	}
	solve(k1, t1);
	solve(k2, t2);
	solve(k3, t3);
	ll res = -1000000000000000000;
	REP (i, n) res = max(res, c[i].X - c[i].Y);
	cout << res << endl;
	return 0;
}