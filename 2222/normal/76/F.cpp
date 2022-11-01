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

int n, V;
pii p[100500];
int f[200500];
ll X[100500];

void setmax(ll x, int v) {
	int i = lower_bound(X, X + n, x) - X;
	for (i += 100500; i && f[i] < v; i /= 2)
		f[i] = v;
}

int getmax(ll x) {
	int i = lower_bound(X, X + n, x) - X, j = n - 1, res = 0;
	for (i += 100500, j += 100500; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
		res = max(res, f[i]);
		res = max(res, f[j]);
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = pii(x, y);
	}
	cin >> V;
	REP (i, n) {
		ll x = p[i].X, y = p[i].Y * V;
		p[i].X = y + x;
		p[i].Y = y - x;
		X[i] = p[i].Y;
	}
	++n;
	sort(p, p + n);
	sort(X, X + n);
	int r0 = 0, r1 = 0;
	for (int i = n; i --> 0; ) {
		int z = getmax(p[i].Y);
		if (p[i].X || p[i].Y) 
			setmax(p[i].Y, ++z);
		else r0 = z;
//		cout << p[i].X << ' ' << p[i].Y << ' ' << z << endl;
		r1 = max(r1, z);
	}
	cout << r0 << ' ' << r1 << endl;
	return 0;
}