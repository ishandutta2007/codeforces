#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 222;

int n, m;
vi u[h*h], e,s;
bool a[h*h][h], y[h];

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	CL(y, 0);
	scanf("%d", &n);
	m = n*(n-1)/2;
	int k;
	REP(i, m)
	{
		scanf("%d", &k);
		u[i].resize(k);
		REP(j, k) scanf("%d", &u[i][j]);
		REP(j, k) a[i][u[i][j]] = 1;
	}
	if(n==2)
	{
		printf("1 %d\n", u[0][0]);
		printf("%d", sz(u[0])-1);
		FOR(i, 1, sz(u[0])) printf(" %d", u[0][i]);
		printf("\n");
		return 0;
	}
	FOR(v, 1, h) if(!y[v])
	{
		e.clear();
		REP(i, m) if(a[i][v]) e.pb(i);
		if(e.empty()) continue;
		s.clear();
		FOR(x, v, h)
		{
			bool ok = true;
			REP(i, sz(e)) if(!a[e[i]][x])
			{	ok = false; break; }
			if(ok)
			{
				s.pb(x);
				y[x] = 1;
			}
		}
		printf("%d", sz(s));
		REP(i, sz(s)) printf(" %d", s[i]);
		printf("\n");
	}
	return 0;
}