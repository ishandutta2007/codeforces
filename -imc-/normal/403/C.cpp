#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

#if 0
const int msize = 3;

void printMatrix(int a[msize][msize])
{
	for (int y = 0; y < msize; y++)
	{
		for (int x = 0; x < msize; x++)
			printf("%d ", a[x][y]);
		printf("\n");
	}
	printf("\n");
}
#endif

const int maxN = 2200;
int aOrig[maxN][maxN];

vector<int> edgesTo[maxN];
vector<int> revEdgesTo[maxN];
vector<int> tsort;
vector<char> used;

void tdfs(int v)
{
	used[v] = true;
	
	for (int u: revEdgesTo[v])
		if (!used[u])
			tdfs(u);
			
	tsort.push_back(v);
}

void dfs(int v)
{
	used[v] = true;
	for (int u: edgesTo[v])
		if (!used[u])
			dfs(u);
}

int main()
{
	#if 0
	int a[msize][msize];
	for (int mask = 0; mask < 1 << msize * msize; mask++)
	{
		int aOrig[msize][msize];
		
		for (int x = 0; x < msize; x++)
			for (int y = 0; y < msize; y++)
				aOrig[x][y] = a[x][y] = (mask & (1 << (y * msize + x))) ? 1 : 0;
	
	
			//printMatrix(a);
			//continue;
				
		bool good = false;
		for (int i = 0; i < msize; i++)
			if (a[i][i])
			{
				good = true;
				break;
			}
		if (!good) continue;
				
		bool allBad = true;
		for (int its = 0; its < 10; its++)
		{
			int b[msize][msize];
			for (int i = 0; i < msize; i++)
				for (int j = 0; j < msize; j++)
				{
					b[i][j] = 0;
					for (int k = 0; k < msize; k++)
						b[i][j] += a[i][k] * a[k][j];
				}
				
			bool bad = false;
			for (int i = 0; i < msize; i++)
				for (int j = 0; j < msize; j++)
				{
					a[i][j] = b[i][j] ? 1 : 0;
					if (!a[i][j]) bad = true;
				}
				
			if (!bad)
			{
				allBad = false;
				break;
			}
		}
		
		printf("%s\n", allBad ? "bad" : "good");
		printMatrix(aOrig);
		if (allBad)
		{
			printf("result:\n");
			printMatrix(a);
		}
	#endif
	
	int msize;
	scanf("%d", &msize);
	
	for (int i = 0; i < msize; i++)
		for (int j = 0; j < msize; j++)
			scanf("%d", &aOrig[i][j]);
	
	tsort.clear();
	for (int i = 0; i < msize; i++)
	{
		edgesTo[i].clear();
		revEdgesTo[i].clear();
	}
	
	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
			if (aOrig[i][j])
			{
				edgesTo[i].push_back(j);
				revEdgesTo[j].push_back(i);
			}
	}
	
	used.assign(msize, false);
	for (int i = 0; i < msize; i++)
		if (!used[i])
			tdfs(i);
	
	used.assign(msize, false);
	dfs(tsort.back());
	
	bool answer = true;
	for (int i = 0; i < msize; i++)
		if (!used[i])
		{
			answer = false;
			break;
		}
			
	#if 0
		printf("answer bad: %s\n", answer ? "not bad" : "bad");
		assert(!answer == allBad);
	}
	#endif
	
	printf("%s\n", answer ? "YES" : "NO");
	
	return 0;
}