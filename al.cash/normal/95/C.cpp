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

const int h = 1111;
int n,m, x,y;
vector<pii> r[h];
ll d[h][h], o[h];
int t[h], c[h];

typedef pair<ll, int> pli;
priority_queue<pli> q;

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &x, &y);
	--x; --y;
	REP(i, m)
	{
		int a,b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		r[a].pb( pii(b, c) );
		r[b].pb( pii(a, c) );
	}
	REP(i, n)
	{
		REP(j, n) d[i][j] = INF_LL;
		d[i][i] = 0;
		q = priority_queue<pli>();
		q.push( pli(0, i) );
		while(!q.empty())
		{
			pli u = q.top();
			q.pop();
			int v = u.Y;
			if(u.X + d[i][v] != 0) continue;
			REP(j, sz(r[v]))
			{
				int w = r[v][j].X;
				if(d[i][w] > d[i][v] + r[v][j].Y)
				{
					d[i][w] = d[i][v] + r[v][j].Y;
					q.push( pli(-d[i][w], w) );
				}
			}
		}
	}
	REP(i, n) scanf("%d%d", t+i, c+i);
	q = priority_queue<pli>();
	REP(i, n) o[i] = INF_LL;
	o[x] = 0;
	q.push( pli(0, x) );
	while(!q.empty())
	{
		pli u = q.top();
		q.pop();
		int v = u.Y;
		if(u.X + o[v] != 0) continue;
		if(v==y) break;
		REP(i, n) if(d[v][i] <= t[v])
		{
			if(o[i] > o[v] + c[v])
			{
				o[i] = o[v] + c[v];
				q.push( pli(-o[i], i) );
			}
		}
	}
	if(o[y] == INF_LL) printf("-1\n");
	else printf("%I64d\n", o[y]);
	//system("PAUSE");
	return 0;
}