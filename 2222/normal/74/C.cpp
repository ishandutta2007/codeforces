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

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m, res = 0;
	cin >> n >> m;
	if (n > m) swap(n, m);
	vector <bool> u(n);
	REP (i, n) if (!u[i]) {
		++res;
		queue <int> Q;
		Q.push(i);
		u[i] = true;
		for (; Q.size(); ) {
			int j = Q.front(); Q.pop();
			int x = (j + 2 * (m - 1)) % (2 * (n - 1));
			if (x >= n - 1) x = 2 * (n - 1) - x;
			if (!u[x]) { u[x] = true; Q.push(x); }
			x = (j - 2 * (m - 1)) % (2 * (n - 1));
			if (x < 0) x += 2 * (n - 1);
			if (x >= n - 1) x = 2 * (n - 1) - x;
			if (!u[x]) { u[x] = true; Q.push(x); }
		}
	}
	cout << res << endl;
	return 0;
}