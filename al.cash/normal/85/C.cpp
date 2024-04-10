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

const int N = 111111;

int n, k, root;
int p[N], v[N], l[N], r[N];
int h[N], vl[N], vr[N];
ll sum[N];
int u[N], q[N];
int ans[N];

bool comp (int x, int y) { return v[x] < v[y]; }

int Vl (int x)
{
	if(l[x] == -1) return v[x];
	if(vl[x] != -1) return vl[x];
	return vl[x] = Vl(l[x]);
}

int Vr (int x)
{
	if(r[x] == -1) return v[x];
	if(vr[x] != -1) return vr[x];
	return vr[x] = Vr(r[x]);
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d", &n);
	REP(i, n)
	{
		scanf("%d%d", &p[i], &v[i]);
		if(p[i]!=-1) --p[i];
	}
	CL(l, -1);
	CL(r, -1);
	REP(i, n) if(p[i]!=-1)
	{
		if(v[i] < v[p[i]]) l[p[i]] = i;
		else r[p[i]] = i;
	}
	else root = i;
	REP(i, n) u[i] = i;
	sort(u, u+n, comp);
	CL(vl, -1);
	CL(vr, -1);
	int a=0, b=1;
	q[0] = root;
	h[root] = 0;
	sum[root] = 0;
	while(a < b)
	{
		int i = q[a++];
		if(l[i]!=-1)
		{
			sum[l[i]] = sum[i] + Vl(r[i]);
			h[l[i]] = h[i] + 1;
			q[b++] = l[i];
			
			sum[r[i]] = sum[i] + Vr(l[i]);
			h[r[i]] = h[i] + 1;
			q[b++] = r[i];
		}
	}
	//REP(i, n) printf("%d: %d, %I64d,%d\n", u[i], v[u[i]], sum[u[i]], h[u[i]]);
	scanf("%d", &k);
	REP(i, k)
	{
		scanf("%d", &v[n]);
		int x = lower_bound(u, u+n, n, comp) - u;
		//printf("%d %d\n", x, u[x]);
		if(x<n && l[u[x]]==-1) printf("%.12lf\n", double(sum[u[x]]) / h[u[x]]);
		else printf("%.12lf\n", double(sum[u[x-1]]) / h[u[x-1]]);
	}
	//system("PAUSE");
	return 0;
}