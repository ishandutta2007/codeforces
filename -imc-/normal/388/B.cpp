#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int nVertices = 2;

int allocate()
{
	assert(nVertices < 1000);
	return nVertices++;
}

bool isEdge[1005][1005];

void edge(int i, int j)
{
	assert(i < nVertices && j < nVertices);
	assert(i != j);
	isEdge[i][j] = isEdge[j][i] = true;
	//printf("Edge %d => %d\n", i + 1, j + 1);
}

int main()
{
	int k;
	scanf("%d", &k);
	
	vector<int> bits;
	
	while (k > 0)
	{
		bits.push_back(k % 2);
		k /= 2;
	}
	
	int chainEnd = allocate(), chainSegments = 1;
	edge(0, chainEnd);
	
	for (int i = bits.size() - 2; i >= 0; i--)
	{
		int u = allocate(), v = allocate(), c = allocate();
		edge(chainEnd, u);
		edge(chainEnd, v);
		edge(u, c);
		edge(v, c);
		chainEnd = c;
		chainSegments += 2;
		
		if (bits[i])
		{
			int last = 0;
			for (int i = 0; i < chainSegments - 1; i++)
			{
				int x = allocate();
				edge(last, x);
				last = x;
			}
			edge(last, chainEnd);
		}
	}
	
	edge(chainEnd, 1);
	
	printf("%d\n", nVertices);
	for (int i = 0; i < nVertices; i++)
	{
		for (int j = 0; j < nVertices; j++)
			printf("%c", isEdge[i][j] ? 'Y' : 'N');
		printf("\n");
	}
	
	return 0;
}