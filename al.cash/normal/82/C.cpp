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

const int h = 5005;

int n;
int a[h], t[h];
vector<pii> r[h];
pii p[h];

vi s[h];

int q[h];

bool comp (int x, int y)
{	return a[x] > a[y]; }

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i), s[i].reserve(n);
	REP(i, n-1)
	{
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		r[a].pb( pii(b, c) );
		r[b].pb( pii(a, c) );
	}
	REP(i, n) p[i].X = -1;
	p[0].X = 0;
	int x=0, k=1;
	q[0] = 0;
	while(x < k)
	{
		int u = q[x++];
		REP(i, sz(r[u]))
		{
			int j = r[u][i].X;
			if(p[j].X == -1)
			{
				p[j] = pii(u, r[u][i].Y);
				q[k++] = j;
			}
		}
	}
	//REP(i, k) printf("%d\n", q[i]);
	REP(i, n) s[i] = vi(1, i);
	int tt = 0;
	k = 0;
while(k < n)
{
	k += sz(s[0]);
	REP(j, sz(s[0])) t[s[0][j]] = tt;
	s[0].clear();
	FOR(i, 1, n)
	{
		int j = q[i];
		if(s[j].empty()) continue;
		sort(all(s[j]), comp);
		for(int c = min(sz(s[j]), p[j].Y); c>0; --c)
		{
			s[p[j].X].pb(s[j].back());
			s[j].pop_back();
		}
	}
	++tt;
}
	REP(i, n) printf("%d ", t[i]);
	printf("\n");
	return 0;
}