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

const int h = 1111, inf = 2012;
int n, a[h], d[4],t, v, m;

int main()
{
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i+1);
	a[0] = 0;
	FOR(i, 1, n+1)
	{
		REP(j, 4) d[j] = a[i]%10, a[i]/=10;
		m = inf;
		REP(j, 4)
		{
			t = d[j];
			FOR(nd, 0, 10) if(nd>0 || j<3)
			{
				d[j] = nd;
				v = 0;
				FORD(u, 3, 0) v = 10*v + d[u];
				if(v>=a[i-1] && v<m) m=v;
			}
			d[j] = t;
		}
		if(m==inf)
		{
			printf("No solution\n");
			return 0;
		}
		a[i] = m;
	}
	FOR(i, 1, n+1) printf("%d\n", a[i]);
	return 0;
}