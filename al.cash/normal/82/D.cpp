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

int n, a[h];

int c[h][h];
pii uc[h][h];

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i);
	REP(i, n)
	{
		c[n][i] = a[i];
		uc[n][i] = pii(i, -1);
	}
	REP(i, n-1)
	{
		c[n-1][i] = max(a[n-1], a[i]);
		uc[n-1][i] = pii(i, n-1);
	}
	FORD(i, n-2, 0) REP(j, i)
	{
		c[i][j] = max(a[i], a[i+1]) + c[i+2][j];
		uc[i][j] = pii(i, i+1);
		int v1 = max(a[j], a[i]) + c[i+2][i+1];
		if(v1 < c[i][j])
		{
			c[i][j] = v1;
			uc[i][j] = pii(j, i);
		}
		int v2 = max(a[j], a[i+1]) + c[i+2][i];
		if(v2 < c[i][j])
		{
			c[i][j] = v2;
			uc[i][j] = pii(j, i+1);
		}
	}
	printf("%d\n", c[1][0]);
	int i = 1, j = 0;
	while(1)
	{
		int a = uc[i][j].X;
		int b = uc[i][j].Y;
		printf("%d", a+1);
		if(b!=-1) printf(" %d", b+1);
		printf("\n");
		if(b==-1 || i==n-1) break;
		if(a==j)
		{
			if(b==i) j=i+1, i=i+2;
			else j=i, i=i+2;
		}
		else i=i+2;
	}
	return 0;
}