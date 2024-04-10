#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct node
{
	node *nxt[26];
	node()
	{
		for (int i = 0; i < 26; i++)
			nxt[i] = NULL;
	}
};

char str[100005];

int fail = 0;

int dfs(node *v)
{
	bool any = false;
	for (int i = 0; i < 26; i++)
		any |= v->nxt[i] != NULL;
		
	if (!any)
		return fail;
		
	int res = 0;
	for (int i = 0; i < 26; i++)
		if (v->nxt[i] != NULL)
		{
			if (!dfs(v->nxt[i]))
				res = 1;
		}
		
	return res;
}

struct matr
{
	int a[2][2];
	
	matr operator * (const matr &b)
	{
		matr res;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				res.a[i][j] = 0;
				for (int k = 0; k < 2; k++)
					res.a[i][j] += a[i][k] * b.a[k][j];
			}
		}
		return res;
	}
};

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	node *root = new node();
	
	int n, k;
	scanf("%d %d\n", &n, &k);
	
	for (int i = 0; i < n; i++)
	{
		gets(str);
		int len = strlen(str);
		
		node *v = root;
		for (int j = 0; j < len; j++)
		{
			str[j] -= 'a';
			if (v->nxt[str[j]] == NULL)
				v->nxt[str[j]] = new node();
			v = v->nxt[str[j]];
		}
	}
	
	
	matr x;
	x.a[0][0] = x.a[1][0] = x.a[0][1] = x.a[1][1] = 0;
	
	
	fail = 0;
	if (dfs(root))
	{
		x.a[1][0] = 1;
	}
	else
	{
		x.a[0][0] = 1;
	}
	
	
	fail = 1;
	
	if (dfs(root))
	{
		x.a[1][1] = 1;
	}
	else
	{
		x.a[0][1] = 1;
	}
	
	
	
	matr res;
	res.a[0][0] = res.a[1][1] = 1;
	res.a[0][1] = res.a[1][0] = 0;
	
	while (k)
	{
		if (k  & 1)
			res = res * x;
		x = x * x;
		k >>= 1;
	}
	
	
	
	if (!res.a[0][0])
		puts("First");
	else
		puts("Second");
	
	
	return 0;
}