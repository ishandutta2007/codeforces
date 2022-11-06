#include<cstdio>
#include<cstring>
#include<vector>
 
using namespace std;
 
struct scheme
{
	char type;
	bool value, influence;
	int father;
	int son[2];
}schemes[1000001];
 
bool dfs(int ord)
{
	switch (schemes[ord].type)
	{
	case 'A':
		schemes[ord].value = dfs(schemes[ord].son[0]) & dfs(schemes[ord].son[1]);
		break;
	case 'O':
		schemes[ord].value = dfs(schemes[ord].son[0]) | dfs(schemes[ord].son[1]);
		break;
	case 'X':
		schemes[ord].value = dfs(schemes[ord].son[0]) ^ dfs(schemes[ord].son[1]);
		break;
	case 'N':
		schemes[ord].value = !dfs(schemes[ord].son[0]);
		break;
	default:
		break;
	}
	return schemes[ord].value;
}
 
void dfs2(int ord)
{
	int father = schemes[ord].father;
	if (!schemes[ord].father)
		schemes[ord].influence = true;
	else
	{
		if (schemes[father].influence)
		{
			switch (schemes[father].type)
			{
			case 'A':
				if (schemes[father].son[0] == ord ? schemes[schemes[father].son[1]].value : schemes[schemes[father].son[0]].value)
					schemes[ord].influence = true;
				else
					schemes[ord].influence = false;
				break;
			case 'O':
				if (schemes[father].son[0] == ord ? schemes[schemes[father].son[1]].value : schemes[schemes[father].son[0]].value)
					schemes[ord].influence = false;
				else
					schemes[ord].influence = true;
				break;
			case 'X':
				schemes[ord].influence = true;
				break;
			case 'N':
				schemes[ord].influence = true;
				break;
			default:
				break;
			}
		}
		else
			schemes[ord].influence = false;
	}
	switch (schemes[ord].type)
	{
	case 'A':
	case 'O':
	case 'X':
		dfs2(schemes[ord].son[0]);
		dfs2(schemes[ord].son[1]);
		break;
	case 'N':
		dfs2(schemes[ord].son[0]);
		break;
	default:
		break;
	}
	return;
}
 
int main()
{
	int n;
	char type[4];
	vector<int> input;
	while (scanf("%d", &n) != EOF)
	{
		input.clear();
		memset(schemes, 0, sizeof(schemes));
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%s", type);
			schemes[i].type = type[0];
			switch (type[0])
			{
			case 'A':
				scanf("%d %d", &x, &y);
				schemes[x].father = i;
				schemes[y].father = i;
				schemes[i].son[0] = x;
				schemes[i].son[1] = y;
				break;
			case 'O':
				scanf("%d %d", &x, &y);
				schemes[x].father = i;
				schemes[y].father = i;
				schemes[i].son[0] = x;
				schemes[i].son[1] = y;
				break;
			case 'X':
				scanf("%d %d", &x, &y);
				schemes[x].father = i;
				schemes[y].father = i;
				schemes[i].son[0] = x;
				schemes[i].son[1] = y;
				break;
			case 'N':
				scanf("%d", &x);
				schemes[x].father = i;
				schemes[i].son[0] = x;
				break;
			default:
				scanf("%d", &x);
				schemes[i].value = x;
				input.push_back(i);
				break;
			}
		}
		dfs(1);
		dfs2(1);
		int sizes = input.size();
		for (int i = 0; i < sizes; i++)
			printf("%d", schemes[input.at(i)].influence ? !schemes[1].value : schemes[1].value);
		printf("\n");
	}
	return 0;
}