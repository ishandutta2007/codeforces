#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node
{
	int parent;
	int respect;
	int respected;
};

int n;
Node Nodes[100001];
//int cache[100001];

vector<int> result;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int p, r;
		scanf("%d%d", &p, &r);
		Nodes[i].parent = p;
		Nodes[i].respect = 1 - r;

		if (p != -1)
		{
			Nodes[p].respected += 1 - r;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (Nodes[i].respect + Nodes[i].respected == 0)
		{
			result.push_back(i);
		}
	}

	if (result.size() == 0)
		printf("-1");
	else
		for (int i = 0; i < result.size(); i++)
			printf("%d ", result[i]);
}