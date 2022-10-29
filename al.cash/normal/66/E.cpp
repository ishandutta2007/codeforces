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

const int h = 100011;
int n, a[h],b[h], sa[h],sb[h], ml[h], mr[h];
bool ok[h];

void work (bool rev)
{
	sa[0] = sb[0] = 0;
	ml[0] = 0;
	REP(i, n)
	{
		sa[i+1] = sa[i] + a[i];
		sb[i+1] = sb[i] + b[i];
		ml[i+1] = min(ml[i], sa[i+1] - sb[i+1]);
	}
	mr[n] = 0;
	//REP(i, n) printf("%d %d\n", a[i], b[i]);
	//REP(i, n+1) printf("%d %d\n", sa[i], sb[i]);
	FORD(i, n-1, 0) mr[i] = min(sa[i+1] - sb[i+1], mr[i+1]);
	//REP(i, n+1) printf("%d %d\n", ml[i], mr[i]);
	//REP(i, n) printf("%d: %d %d\n", i, mr[i] + (sa[i] - sb[i]), ml[i] + (sa[n]-sb[n]) - (sa[i]-sb[i]));
	REP(i, n) if(mr[i] - (sa[i] - sb[i]) >= 0 && ml[i] + (sa[n]-sb[n]) - (sa[i]-sb[i]) >= 0)
	{
		if(rev) ok[n-i-1] = true;
		else ok[i] = true;
	}
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i);
	REP(i, n) scanf("%d", b+i);
	work (false);
	reverse(a, a+n);
	reverse(b, b+n-1);
	work (true);
	int k = 0;
	REP(i, n) if(ok[i]) ++k;
	printf("%d\n", k);
	REP(i, n) if(ok[i]) printf("%d ", i+1);
	printf("\n");
	return 0;
}