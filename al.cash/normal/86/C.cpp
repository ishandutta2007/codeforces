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

const int mod = 1000000009;
void inc (int &a, int b) { a+=b; if(a>=mod) a-=mod; }
int add (int a, int b) { return (a+b) % mod; }
int mul (int a, int b) { return ll(a)*b % mod; }

char al[5]="ACGT";

int n, m;
char s[22];

const int h = 111;
int t[h][4], f[h], l[h],lx[h], nv=1;
bool y[h];
vector<int> q;

int dp[1111][h][12];

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	CL(t, 0);
	CL(y, 0);
	REP(i, m)
	{
		scanf("%s", s);
		int v = 0;
		REP(j, strlen(s))
		{
			int x = 0;
			while(al[x]!=s[j]) ++x;
			if(t[v][x]==0) t[v][x] = nv++;
			v = t[v][x];
		}
		y[v] = 1;
	}
	int a = 0;
	q.clear();
	q.pb(0);
	f[0] = 0;
	l[0] = 0;
	while(a<sz(q))
	{
		int v = q[a++];
		//y[v] |= y[f[v]];
		REP(j, 4) if(t[v][j]!=0)
		{
			int w = f[v], u = t[v][j];
			while(w!=0 && t[w][j]==0) w = f[w];
			if(v==0) f[u] = 0;
			else f[u] = t[w][j];

			q.pb(u);
			l[u] = l[v]+1;
		}
		if(y[v]) lx[v] = l[v];
		else lx[v] = lx[f[v]];
		REP(j, 4) if(t[v][j]==0)
			t[v][j] = t[f[v]][j];
	}
	//REP(i, nv) printf("%d,%d ", f[i], lx[i]); printf("\n");
	dp[0][0][0] = 1;
	REP(i, n) REP(v, nv) REP(c, l[v]+1) REP(j, 4)
	{
		int u = t[v][j];
		if(l[u]<c+1) continue;
		if(lx[u]>=c+1) inc(dp[i+1][u][0], dp[i][v][c]);
		else inc(dp[i+1][u][c+1], dp[i][v][c]);
	}
	/*REP(i, n+1)
	{
		REP(v, nv)
		{
			printf("(");
			REP(c, l[v]+1) printf("%d,", dp[i][v][c]);
			printf(") ");
		}
		printf("\n");
	}*/
	int ans = 0;
	REP(v, nv) inc(ans, dp[n][v][0]);
	printf("%d\n", ans);
	//system("PAUSE");
	return 0;
}