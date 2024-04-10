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

const int N = 1111;
int n, h[N], l[N],r[N];

int main()
{
	scanf("%d", &n);
	REP(i, n) scanf("%d", h+i+1);
	h[0] = h[n+1] = INF;
	FOR(i, 1, n+1)
	{
		l[i] = 1;
		if(h[i] >= h[i-1]) l[i] += l[i-1];
	}
	FORD(i, n, 1)
	{
		r[i] = 1;
		if(h[i] >= h[i+1]) r[i] += r[i+1];
	}
	int ans = 0;
	FOR(i, 1, n+1) ans = max(ans, l[i]+r[i]-1);
	printf("%d\n", ans);
	return 0;
}