#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
struct Node
{
	bool m;
	vector <int> leaf;
};

Node Nodes[300001];

int result = 0;
int howManyLeafUpper(int curIndex)
{
	if (Nodes[curIndex].leaf.size() == 0)
		return 1;

	if (Nodes[curIndex].m)
	{
		int result = 987654321;
		for (int i = 0; i < Nodes[curIndex].leaf.size(); i++)
			result = min(result, howManyLeafUpper(Nodes[curIndex].leaf[i]));

		return result;
	}
	else
	{
		int result = 0;
		for (int i = 0; i < Nodes[curIndex].leaf.size(); i++)
			result += howManyLeafUpper(Nodes[curIndex].leaf[i]);

		return result;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		Nodes[i].m = tmp;
	}

	for (int i = 1; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		Nodes[tmp - 1].leaf.push_back(i);
	}

	int maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (Nodes[i].leaf.size() == 0)
			maxNum++;
	}

	cout << maxNum - howManyLeafUpper(0) + 1;
}