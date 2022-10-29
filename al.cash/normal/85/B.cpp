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

const int h = 111111;

int t[3], k[3];
int n, c[h];

typedef pair<ll, int> pli;
priority_queue<pli> w[3], e[3];

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	REP(i, 3) scanf("%d", k+i);
	REP(i, 3) scanf("%d", t+i);
	scanf("%d", &n);
	REP(i, n) scanf("%d", c+i);
	REP(i, n) w[0].push( pli(-c[i], -i) );
	ll ans = 0;
	bool ok = true;
	while(true)
	{
		ll tt = INF_LL;
		REP(i, 3)
		{
			if(ok && !w[i].empty()) tt = min(tt, -w[i].top().X);
			if(!e[i].empty()) tt = min(tt, -e[i].top().X);
		}
		if(tt == INF_LL) break;
		ok = false;
		pli u;
		REP(i, 3) if(!e[i].empty())
		{
			u = e[i].top();
			if(-u.X > tt) continue;
			ok = true;
			//printf("e%d %d %d\n", i, -u.Y, -u.X);
			e[i].pop();
			++k[i];
			if(i!=2) w[i+1].push( pli(u.X, u.Y) );
			else ans = max(ans, -u.X - c[-u.Y]);
		}
		REP(i, 3) if(k[i]>0 && !w[i].empty())
		{
			u = w[i].top();
			if(-u.X > tt) continue;
			ok = true;
			//printf("w%d %d %d\n", i, -u.Y, -u.X);
			w[i].pop();
			--k[i];
			e[i].push( pli(-tt-t[i], u.Y) );
		}
	}
	cout << ans << endl;
	//system("PAUSE");
	return 0;
}