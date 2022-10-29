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
typedef pair<string, int> psi;

vector<psi> t[10011];
int kf[10011], kd[10011], v,nv=5;
int mf=0,md=0, cf,cd;
char c, s[111];
string f;

void go (int v)
{
	cf += kf[v];
	cd += kd[v];
	REP(i, sz(t[v])) go(t[v][i].Y);
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	while(scanf("%c:\\%s\n", &c, s)==2)
	{
		v = c-'C';
		int n=strlen(s);
		for(int i=0, j=0; j<n; ++j) if(s[j]=='\\')
		{
			f.clear();
			while(i<j) f += s[i++];
			++i;
			//printf("%d %s\n", v, f.c_str());
			bool ok = false;
			REP(u, sz(t[v])) if(t[v][u].X == f)
			{
				ok = true;
				v = t[v][u].Y;
				break;
			}
			if(!ok)
			{
				++kd[v];
				t[v].pb( psi(f, nv) );
				v = nv++;
			}
		}
		++kf[v];
	}
	REP(s, 5) REP(i, sz(t[s]))
	{
		cf = cd = 0;
		go(t[s][i].Y);
		mf = max(mf, cf);
		md = max(md, cd);
	}
	printf("%d %d\n", md, mf);
	return 0;
}