#include <bits/stdc++.h>
#define MAXN 1005
#define MAXM 30005
#define MYINF 2000000005

using namespace std;

struct edge
{
	int b, w, id;
	char p;
};

static vector<struct edge> a[MAXN];

static char b[MAXN];
static pair<int, int> w[MAXN];
static int h[MAXN];

void DFS1 (int point)
{
	for (int i = 0; i < (int)a[point].size(); i++)
	{
		if (a[point][i].p)
		{
			int j = a[point][i].b;
			if (!b[j])
			{
				b[j] = 1;
				w[j] = make_pair(point, a[point][i].id);
				DFS1(j);
			}
		}
	}
}

static char bridges[MAXM];

int DFS2 (int point, int par, int curH)
{
	h[point] = curH;
	int minH = curH;
	for (int i = 0; i < (int)a[point].size(); i++)
	{
		if (a[point][i].p)
		{
			int j = a[point][i].b;
			if (a[point][i].id != par)
			{
				if (!b[j])
				{
					b[j] = 1;
					minH = min(minH, DFS2(j, a[point][i].id, curH+1));
				}
				else
				{
					minH = min(minH, h[j]);
				}
			}
		}
	}

	if ((minH >= curH) && (par != -1))
	{
		bridges[par] = 1;
	}

	return minH;
}

static int wgs[MAXM];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int S, T;
	scanf("%d %d", &S, &T);
	S--; T--;

	int i, x, y, wg;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d",&x,&y,&wg);
		x--; y--;

		struct edge e1;
		e1.b = y;
		e1.w = wg;
		e1.id = i+1;
		e1.p = 1;
		a[x].push_back(e1);

		struct edge e2;
		e2.b = x;
		e2.w = wg;
		e2.id = i+1;
		e2.p = 1;
		a[y].push_back(e2);

		wgs[i+1] = wg;
	}

	memset(b, 0, sizeof(b));
	b[S] = 1;
	w[S] = make_pair(-1, -1);
	DFS1(S);

	if (!b[T])
	{
		printf("0\n0\n");
		return 0;
	}

	static vector< pair< pair<int, int>, int> > path;
	i = T;
	while (i != S)
	{
		int j = w[i].first;
		path.push_back(make_pair(make_pair(i, j), w[i].second));
		i = j;
	}

	int res = MYINF;
	int resa = -1;
	int resb = -1;

	for (auto e : path)
	{
		x = e.first.first;
		y = e.first.second;
		int id = e.second;
		int cost = wgs[id];
		for (struct edge &e2 : a[x])
		{
			if (e2.id == id) e2.p = 0;
		}
		for (struct edge &e2 : a[y])
		{
			if (e2.id == id) e2.p = 0;
		}

		memset(b, 0, sizeof(b));
		b[S] = 1;
		w[S] = make_pair(-1, -1);
		DFS1(S);
		if (!b[T])
		{
			if (cost < res)
			{
				res = cost;
				resa = id;
				resb = -1;
			}
		}
		else
		{
			memset(b, 0, sizeof(b));
			b[S] = 1;
			memset(bridges,0,sizeof(bridges));
			DFS2(S, -1, 0);

			i = T;
			while (i != S)
			{
				int j = w[i].first;
				int id2 = w[i].second;
				int wg2 = wgs[id2];
				if (bridges[id2])
				{
					if (cost + wg2 < res)
					{
						res = cost + wg2;
						resa = id;
						resb = id2;
					}
				}
				i = j;
			}
		}

		for (struct edge &e2 : a[x])
		{
			if (e2.id == id) e2.p = 1;
		}
		for (struct edge &e2 : a[y])
		{
			if (e2.id == id) e2.p = 1;
		}
	}
	
	if (res == MYINF)
	{
		printf("-1\n");
		return 0;
	}

	if (resb == -1)
	{
		printf("%d\n1\n%d\n",res,resa);
	}
	else
	{
		printf("%d\n2\n%d %d\n",res,resa,resb);
	}

	return 0;
}