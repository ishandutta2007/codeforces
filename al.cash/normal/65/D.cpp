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

const int h = 1<<15;
const string sc[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

set<ll> c, t;

int n, k[4];
char s[h];
bool y[4];

inline void encode (ll x)
{
	REP(i, 4) k[i] = x&(h-1), x>>=15;
}

inline void add ()
{
	ll x = 0;
	FORD(i, 3, 0) x = (x<<15LL) + k[i];
	t.insert(x);
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%s", &n, s);
	c.insert(0);
	REP(u, n)
	{
		//printf("%d\n", u);
		t.clear();
		if(s[u]=='?')
		{
			for(set<ll>::iterator it = c.begin(); it != c.end(); ++it)
			{
				encode(*it);
				//REP(i, 4) printf("%d ", k[i]); printf("\n");
				int m = h;
				REP(i, 4) m = min(m, k[i]);
				REP(i, 4) if(k[i]==m)
				{
					++k[i];
					add ();
					--k[i];
				}
			}
		}
		else
		{
			int x = 0;
			while(sc[x][0] != s[u]) ++x;
			for(set<ll>::iterator it = c.begin(); it != c.end(); ++it)
			{
				encode(*it);
				//REP(i, 4) printf("%d ", k[i]); printf("\n");
				++k[x];
				add ();
			}
		}
		c = t;
	}
	for(set<ll>::iterator it = c.begin(); it != c.end(); ++it)
	{
		encode(*it);
		int m = h;
		REP(i, 4) m = min(m, k[i]);
		REP(i, 4) if(k[i]==m) y[i] = true;
	}
	REP(i, 4) if(y[i]) printf("%s\n", sc[i].c_str());
	return 0;
}