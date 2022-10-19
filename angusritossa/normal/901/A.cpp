#include <bits/stdc++.h>
using namespace std;
int a[1000010], par1[1000010], par2[1000010];
int upto;
bool done = false;
void dfs1(int par = 0, int h = 0)
{
	int first = upto;
	for (int i = 0; i < a[h]; i++)
	{
		par1[upto++] = par;
	}
	if (a[h]) dfs1(first, h+1);
}
vector<int> at;
void dfs2(int h = 0)
{
	int first = upto;
	vector<int> b;
	if (at.size() == 1)
	{
		for (int i = 0; i < a[h]; i++)
		{
			b.push_back(upto);
			par2[upto++] = at[0];
		}
	}
	else if (at.size() >= 2)
	{
		if (a[h])
		{
			par2[upto] = at[0];
			b.push_back(upto++);
		}
		for (int i = 1; i < a[h]; i++)
		{
			par2[upto] = at[1];
			b.push_back(upto++);
		}
	}
	else return;
	at = b;
	if (b.size()) dfs2(h+1);
}
bool last, possible;
int main()
{
	int H;
	scanf("%d", &H);
	for (int i = 0; i <= H; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > 1)
		{
			if (last) possible = true;
			last = true;
		}
		else last = false;
	}
	if (!possible) printf("perfect\n");
	else 
	{
		upto++;
		dfs1(0);
		printf("ambiguous\n");
		for (int i = 1; i < upto; i++)
		{
			printf("%d ", par1[i]);
		}
		printf("\n");
		upto = 1;
		at.push_back(0);
		dfs2(0);

		for (int i = 1; i < upto; i++)
		{
			printf("%d ", par2[i]);
		}
		printf("\n");
	}
}