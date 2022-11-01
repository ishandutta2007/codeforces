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

int n, m, k;
int p[1111111], c[1111111];

int sid(int x) {
	int y = x, z;
	for (; p[y] != y; y = p[y]);
	for (; x != y; x = z) {
		z = p[x];
		p[x] = y;
	}
	return x;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	REP (i, n) p[i] = i;
	REP (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[sid(x - 1)] = sid(y - 1);
	}
	REP (i, n)
		if (++c[sid(i)] > k)
			c[sid(i)] = k;
	priority_queue< int, vector<int>, greater<int> > Q;
	int m = accumulate(c, c + n, 0);
	REP (i, n) if (c[i]) Q.push(c[i]);
	int res = 0;
	for (; sz(Q) > 1; ++res) {
		if ((m / 2) + 1 >= Q.size()) 
			break;
		int x = Q.top(); Q.pop();
		int y = Q.top(); Q.pop();
		m -= x + y;
		x = min(x + y, k);
		m += x;
		Q.push(x);
	}
	cout << res << endl;
	return 0;
}