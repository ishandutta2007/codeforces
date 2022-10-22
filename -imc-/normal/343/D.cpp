#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int maxN = 500500;
vector <int> edgesTo[maxN];
int timeCounter;
pair <int, int> interval[maxN];
int vertexCounter[maxN];

pair <int, int> dfs (int v, int p = -1)
{
	pair <int, int> initial (timeCounter, timeCounter);
	vertexCounter[v] = timeCounter++;
	//printf ("Vertex %d => %d\n", v + 1, vertexCounter[v]);

	for (int u: edgesTo[v])
		if (u != p)
		{
			pair <int, int> t = dfs (u, v);

			if (t.first < initial.first)
				initial.first = t.first;
			if (t.second > initial.second)
				initial.second = t.second;
		}

	interval[v] = initial;
	return initial;
}

int intervalValue[maxN * 4];

void assign (int t, int l, int r, int x, int y, int value)
{
	if (x > r || y < l) return;

	if (l >= x && r <= y)
	{
		intervalValue[t] = value;
		return;
	}

	if (intervalValue[t])
	{
	intervalValue[t * 2 + 1] = intervalValue[t];
	intervalValue[t * 2 + 2] = intervalValue[t];
	}
	intervalValue[t] = 0;
	//printf ("propose %d\n", t);

	int m = (l + r) / 2;
	assign (t * 2 + 1, l, m, x, y, value);
	assign (t * 2 + 2, m + 1, r, x, y, value);
}

int query (int t, int l, int r, int x)
{
	if (intervalValue[t] > 0 || l == r)
		return intervalValue[t];

	int m = (l + r) / 2;

	if (x <= m)
		return query (t * 2 + 1, l, m, x);
	else
		return query (t * 2 + 2, m + 1, r, x);
}

const int infinity = 10000000;
int minTree[maxN * 4];

int queryMin (int t, int l, int r, int x, int y)
{
	if (x > r || y < l) return -infinity;

	if (l >= x && r <= y)
		return minTree[t];

	int m = (l + r) / 2;
	return max (queryMin (t * 2 + 1, l, m, x, y), queryMin (t * 2 + 2, m + 1, r, x, y));
}

void changeMin (int t, int l, int r, int x, int value)
{
	if (l == r)
		return void (minTree[t] = value);

	int m = (l + r) / 2;

	if (x <= m)
		changeMin (t * 2 + 1, l, m, x, value);
	else
		changeMin (t * 2 + 2, m + 1, r, x, value);

	minTree[t] = max (minTree[t * 2 + 1], minTree[t * 2 + 2]);
}

int main()
{
	int nVertices;
	scanf ("%d", &nVertices);

	for (int i = 0; i < nVertices - 1; i++)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		a--;
		b--;

		edgesTo[a].push_back (b);
		edgesTo[b].push_back (a);
	}

	pair <int, int> range = dfs (0);
	//printf ("range %d %d\n", range.first, range.second);
	assert (range.first == 0);
	assert (range.second == nVertices - 1);

	int nQueries;
	scanf ("%d", &nQueries);

	timeCounter = 1;

	for (int i = 0; i < nQueries; i++)
	{
		int type, vertex;
		scanf ("%d %d", &type, &vertex);
		vertex--;

		if (type == 1)
		{
			//printf ("assign vertex interval %d..%d to filled\n", interval[vertex].first, interval[vertex].second);
			assign (0, 0, nVertices - 1, interval[vertex].first, interval[vertex].second, timeCounter++);
		}
		else if (type == 2)
		{
			//printf ("assign vertex %d and parents to not filled\n", vertexCounter[vertex]);
			changeMin (0, 0, nVertices - 1, vertexCounter[vertex], timeCounter++);
		}
		else
		{
			assert (type == 3);
			int lastFilled = query (0, 0, nVertices - 1, vertexCounter[vertex]);
			int lastEmpted = queryMin (0, 0, nVertices - 1, interval[vertex].first, interval[vertex].second);
			//printf ("query vertex %d (%d..%d) (last filled %d, last empted %d)\n", vertexCounter[vertex], interval[vertex].first, interval[vertex].second, lastFilled, lastEmpted);
			printf ("%d\n", lastEmpted >= lastFilled ? 0 : 1);
		}
	}

	return 0;
}