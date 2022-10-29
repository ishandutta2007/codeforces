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

const char r[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
const char s[4] = {'C','D','H','S'};

int n,m;
string c[50][50];
vector<string> l;

pii u[2], a[2];

bool g[50][50];

bool check ()
{
	REP(i, n-2) REP(j, m-2)
	{
		bool ss = true, dr = true;
		FOR(ii, i, i+3) FOR(jj, j, j+3)
		{
			if(c[ii][jj][1] != c[i][j][1]) ss = false;
			FOR(i1, i, i+3) FOR(j1, j, j+3)
				if((ii!=i1 || jj!=j1) && c[ii][jj][0] == c[i1][j1][0]) dr = false;
		}
		g[i][j] = ss || dr;
	}
	REP(i1, n-2) REP(j1, m-2) if(g[i1][j1])
		REP(i2, n-2) REP(j2, m-2) if(g[i2][j2])
			if(abs(i1-i2)>=3 || abs(j1-j2)>=3)
			{
				a[0] = pii(i1, j1);
				a[1] = pii(i2, j2);
				return true;
			}
	return false;
}

void fin ()
{
	printf("Put the first square to (%d, %d).\n", a[0].X+1, a[0].Y+1);
	printf("Put the second square to (%d, %d).\n", a[1].X+1, a[1].Y+1);
	exit(0);
}

int main()
{
#ifdef LocalHost
freopen("x.in", "r", stdin);
freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	u[0]=u[1] = pii(-1, -1);
	REP(i, n) REP(j, m)
	{
		cin>>c[i][j];
		if(c[i][j][0] == 'J')
			u[c[i][j][1]-'1'] = pii(i, j);
	}
	REP(ir, 13) REP(is, 4)
	{
		bool no = true;
		string x("  ");
		x[0] = r[ir];
		x[1] = s[is];
		REP(i, n) REP(j, m) if(c[i][j]==x)
		{	no = false; break; }
		if(no) l.pb(x);
	}
	if(u[0].X==-1)
	{
		if(u[1].X==-1)
		{
			if(check())
				printf("Solution exists.\nThere are no jokers.\n"), fin();
		}
		else REP(i, sz(l))
		{
			c[u[1].X][u[1].Y] = l[i];
			if(check())
				printf("Solution exists.\nReplace J2 with %s.\n", l[i].c_str()), fin();
		}
	}
	else
	{
		if(u[1].X==-1)
		{
			REP(i, sz(l))
			{
				c[u[0].X][u[0].Y] = l[i];
				if(check())
					printf("Solution exists.\nReplace J1 with %s.\n", l[i].c_str()), fin();
			}
		}
		else
		{
			REP(i, sz(l)) REP(j, sz(l)) if(i!=j)
			{
				c[u[0].X][u[0].Y] = l[i];
				c[u[1].X][u[1].Y] = l[j];
				if(check())
					printf("Solution exists.\nReplace J1 with %s and J2 with %s.\n", l[i].c_str(), l[j].c_str()), fin();
			}
		}
	}
	printf("No solution.\n");
	return 0;
}