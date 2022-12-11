#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define err(...) fprintf(stderr. __VA_ARGS__)

#define fore(i,n) for(int i = 0; i < n; i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef pair<int,int> pi;
typedef pair<long long, int> pl;
typedef vector<int> vi;

#define maxn 1010
#define inf 1000000000000000LL

vector<pi> g[maxn], h[maxn];
long long dist[maxn][maxn], dst[maxn];
int c[maxn], t[maxn], ct[maxn];
int n,m,x,y,a,b,d;

void dijkstra(int u)
{
	fore(i,n) dist[u][i] = inf;
	dist[u][u] = 0;
	fore(i,n) c[i] = 0;
	priority_queue<pl, vector<pl>, greater<pl> > q;
	q.push(mp(0,u));
	while(!q.empty())
	{
		pi p = q.top();
		q.pop();
		int v = p.y;
		if(c[v]) continue;
		c[v] = 1;
		tr(i,g[v])
		{
			int w = i->x, d = i->y;
			if(dist[u][w] > dist[u][v] + d)
			{
				dist[u][w] = dist[u][v] + d;
				q.push(mp(dist[u][w], w));
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	x--; y--;
	fore(i,m)
	{
		scanf("%d%d%d", &a, &b, &d);
		a--; b--;
		g[a].pb(mp(b,d));
		g[b].pb(mp(a,d));
	}
	fore(i,n) scanf("%d%d", &t[i], &ct[i]);
	fore(i,n) dijkstra(i);
	/*
	fore(i,n)
	{
		fore(j,n) printf("%lld ", dist[i][j]);
		printf("\n");
	}
	*/
	fore(i,n) fore(j,n) if(dist[i][j] <= t[i])
	{
		//printf("sciezka %d -> %d o koszcie %d\n", i, j, ct[i]);
		h[i].pb(mp(j, ct[i]));
	}
	fore(i,n) dst[i] = inf;
	dst[x] = 0;
	fore(i,n) c[i] = 0;
	priority_queue<pl, vector<pl>, greater<pl> > q;
	q.push(mp(0,x));
	while(!q.empty())
	{
		pi p = q.top();
		q.pop();
		int v = p.y;
		if(v == y)
		{
			cout << dst[v] << endl;
			return 0;
		}
		if(c[v]) continue;
		c[v] = 1;
		tr(i,h[v])
		{
			int w = i->x, d = i->y;
			if(dst[w] > dst[v] + d)
			{
				dst[w] = dst[v] + d;
				q.push(mp(dst[w], w));
			}
		}
	}
	printf("-1\n");
}