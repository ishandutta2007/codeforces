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
typedef pair <int, int> pii;

const int L = 450;

int n, m;
int a[200500];
pii Q[200500], S[200500];
ll ANS[200500];

ll f[200500 * 2];

void add(int i, ll v) {
	for (i += n; i; i /= 2)
		f[i] += v;
}

ll sum(int i, int j) {
	ll res = 0;
	for (i += n, j += n; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
		if (i & 1) res += f[i];
		if (~j & 1) res += f[j];
	}
	return res;
}
	
map<int, vi> pos;
vi Z;

ll solve(int i, int j) {
	ll res = sum(i, j);
	for (int x : Z) {
		vi &p = pos[x];
		int k = p.end() - lower_bound(all(p), i);
		res += ll(x) * k * k;
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, n) scanf("%d", a + i);
	REP (i, m) {
		scanf("%d%d", &Q[i].Y, &Q[i].X);
		--Q[i].X;
		--Q[i].Y;
		S[i] = Q[i];
	}
	sort(S, S + m);
	int j = 0;
	REP (i, n) {
		vi &p = pos[a[i]];
		p.pb(i);
		if (sz(p) == L) {
			Z.pb(a[i]);
			for (int x : p)
				add(x, -f[x + n]);
		} else if (sz(p) < L) {
			int k = sz(p);
			for (int x : p) {
				--k;
				add(x, a[i] * ll(2 * k + 1) -f[x + n]);
			}
		}
		for (; j < m && S[j].X == i; ++j) 
			ANS[j] = solve(S[j].Y, S[j].X);
	}
	REP (i, m) cout << ANS[lower_bound(S, S + m, Q[i]) - S] << endl;
	return 0;
}