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

int n,m, a,b;
int d;
char s[1111];
bool y[222][55];

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%d%d%s%s", &n, &a, &b, s, s);
	--a; --b;
//	gets(s);
	//printf("%c\n", s[0]);
	if(s[0]=='t') d=1;
	else d=-1;
	scanf("%s", s);
	m = strlen(s);
	y[0][a] = 1;
	REP(i, m-1)
	{
		//REP(j, n) printf("%d", y[i][j]); printf("\n");
		if(s[i]=='0')
		{
			REP(j, n)
			{
				y[i+1][j] = y[i][j];
				if(j>0) y[i+1][j] |= y[i][j-1];
				if(j<n-1) y[i+1][j] |= y[i][j+1];
			}
			y[i+1][b] = 0;
			b += d;
			if(b==0 || b==n-1) d = -d;
			y[i+1][b] = 0;
		}
		else
		{
			b += d;
			if(b==0 || b==n-1) d = -d;
			REP(j, n) y[i+1][j] = 1;
			y[i+1][b] = 0;
		}
		int k = 0;
		REP(j, n) k += y[i+1][j];
		if(k==0)
		{
			printf("Controller %d\n", i+1);
			return 0;
		}
	}
	printf("Stowaway\n");
	return 0;
}