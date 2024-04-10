#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn  100100
#define M (1<<17)

int n,k;
int a[2*M+17];
long long b[2*M+13];
int g[maxn][2];
int p[maxn], v[maxn], c[maxn], w[maxn];
int minv[maxn], maxv[maxn];
pair<int,int> s[maxn];
pair<int,long double> res[maxn];

void add(int low, int high, int val)
{
	if(low == high) return;
	low += M;
	high += M;
	a[low]++;
	b[low] += val;
	while(low+1 < high)
	{
		if((low&1) == 0)
		{
			a[low+1]++;
			b[low+1] += val;
		}
		if((high&1) == 1)
		{
			a[high-1]++;
			b[high-1] += val;
		}
		low >>= 1;
		high >>= 1;
	}
}

void go(int u, int low, int high)
{
	if(g[u][0] == -1) return;
	int mid = lower_bound(s+low, s+high, make_pair(v[u], 0)) - s;
	add(low, mid, minv[g[u][1]]);
	add(mid, high, maxv[g[u][0]]);
	go(g[u][0], low, mid);
	go(g[u][1], mid, high);
}

void dfs(int i)
{
	w[i] = 1;
	if(p[i] < 0) return;
	minv[p[i]] = min(minv[p[i]], minv[i]);
	maxv[p[i]] = max(maxv[p[i]], maxv[i]);
	if(g[p[i]][0] == -1) g[p[i]][0] = i;
	else g[p[i]][1] = i;
	c[p[i]]--;
	if(c[p[i]] == 0) dfs(p[i]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i], &v[i]);
		p[i]--;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &s[i].first);
		s[i].second = i;
	}
	sort(s,s+k);
	for(int i = 0; i < n; i++)
	{
		minv[i] = 1e9+7;
		maxv[i] = -1;
		g[i][0] = g[i][1] = -1;
	}
	for(int i = 0; i < n; i++) if(p[i] >= 0) c[p[i]]++;
	for(int i = 0; i < n; i++) if(c[i] == 0 && w[i] == 0)
	{
		minv[i] = maxv[i] = v[i];
		dfs(i);
	}
	for(int i = 0; i < n; i++) if(g[i][0] != -1)
	{
		if(v[g[i][0]] > v[g[i][1]]) swap(g[i][0], g[i][1]);
	}
	for(int i = 0; i < n; i++) if(p[i] == -2) go(i,0,k);
	for(int i = 1; i < M; i++)
	{
		a[2*i] += a[i];
		a[2*i+1] += a[i];
		b[2*i] += b[i];
		b[2*i+1] += b[i];
	}
	for(int i = 0; i < k; i++) res[i] = make_pair(s[i].second, (long double)(b[i+M]) / a[i+M]);
	sort(res,res+k);
	for(int i = 0; i < k; i++) printf("%.10Lf\n", res[i].second);
}