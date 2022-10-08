#include <stdio.h>
#include <queue>

int n, m;
int ind[100000], nexus[400000], to[400000], cost[400000], p;
int dist[100000];
int fath[100000], fathlen[100000];

int depth[100000];
int metafath[18][100000];
int metamax[18][100000];

using namespace std;

struct id
{
	int data;
	int dist;
	int ori;

	id () {}
	id (int _data, int _dist, int _ori) : data(_data), dist(_dist), ori(_ori) {}
};

bool operator < (const id& a, const id& b)
{
	return a.dist > b.dist;
}

priority_queue<id> Q;

void KO (int x)
{
	for (int i = ind[x]; i != -1; i = nexus[i])
		if (cost[i] < dist[to[i]])
		{
			dist[to[i]] = cost[i];
			Q.push(id(to[i], dist[to[i]], x));
		}
}

void get_depth (int x)
{
	if (fath[x] == -1)
		depth[x] = 0;
	else
	{
		if (depth[fath[x]] == -1)
			get_depth(fath[x]);
		depth[x] = depth[fath[x]] + 1;
	}
}

void get_metafath (int x, int y)
{
	if (x == 0)
	{
		metafath[x][y] = fath[y];
		metamax[x][y] = ::fathlen[y];
	}
	else
	{
		if (metafath[x - 1][y] == -1)
			get_metafath(x - 1, y);
		if (metafath[x - 1][metafath[x - 1][y]] == -1)
			get_metafath(x - 1, metafath[x - 1][y]);

		metafath[x][y] = metafath[x - 1][metafath[x - 1][y]];
		metamax[x][y] = std::max(metamax[x - 1][y], metamax[x - 1][metafath[x - 1][y]]);
	}
}

int get_max_edge (int a, int b)
{
	int da = depth[a], db = depth[b];

	int re = -1;

	if (da > db)
	{
		for (int i = 17; i >= 0; i --)
			if (da - (1 << i) >= db)
			{
				da -= (1 << i);
				if (metamax[i][a] > re)
					re = metamax[i][a];
				a = metafath[i][a];
			}
	}

	if (db > da)
	{
		for (int i = 17; i >= 0; i --)
			if (db - (1 << i) >= da)
			{
				db -= (1 << i);
				if (metamax[i][b] > re)
					re = metamax[i][b];
				b = metafath[i][b];
			}
	}

	if (a != b)
	{
		for (int i = 17; i >= 0; i --)
			if (da - (1 << i) >= 0 && metafath[i][a] != metafath[i][b])
			{
				da -= (1 << i);
				db -= (1 << i);
				if (metamax[i][a] > re)
					re = metamax[i][a];
				if (metamax[i][b] > re)
					re = metamax[i][b];
				a = metafath[i][a];
				b = metafath[i][b];
			}

		if (metamax[0][a] > re)
			re = metamax[0][a];
		if (metamax[0][b] > re)
			re = metamax[0][b];
	}

	return re;
}

int main ()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i ++)
		ind[i] = -1;
	p = 0;

	for (int i = 0; i < m; i ++)
	{
		int a, b, c;

		scanf ("%d%d%d", &a, &b, &c);
		a --;
		b --;

		nexus[p] = ind[a];
		to[p] = b;
		cost[p] = c;
		ind[a] = p ++;

		nexus[p] = ind[b];
		to[p] = a;
		cost[p] = c;
		ind[b] = p ++;
	}

	for (int i = 0; i < n; i ++)
		fath[i] = -1;

	for (int i = 0; i < n; i ++)
		dist[i] = 100001;
	dist[0] = 0;

	for (int i = 1; i < n; i ++)
		Q.push(id(i, dist[i], 0));

	KO(0);

	long long total = 0;
	int bad = 0;

	for (int i = 1; i < n; i ++)
	{
		int cur, ori;

		do 
		{
			cur = Q.top().data;
			ori = Q.top().ori;

			Q.pop();
		} while (fath[cur] != -1);

		if (dist[cur] == 100001)
			bad ++;

		KO(cur);

		total += dist[cur];
		fath[cur] = ori;
		fathlen[cur] = dist[cur];
	}

	for (int i = 0; i < n; i ++)
		depth[i] = -1;
	for (int i = 0; i < n; i ++)
		if (depth[i] == -1)
			get_depth(i);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= 17; j ++)
			metafath[j][i] = -1;

	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= 17 && (1 << j) <= depth[i]; j ++)
			get_metafath(j, i);

	int q;

	scanf ("%d", &q);
	for (int i = 0; i < q; i ++)
	{
		int a, b;

		scanf ("%d%d", &a, &b);

		a --;
		b --;

		int max_edge = get_max_edge(a, b);

		if (bad == 0 || bad == 1 && max_edge == 100001)
			printf ("%I64d\n", total - max_edge);
		else
			printf ("-1\n");
	}

	return 0;
}