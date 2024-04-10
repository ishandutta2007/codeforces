#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int MAXN = 100007;
const int MAXT = 2000000;
const int INF = (int)1e+9;

int a[MAXN];
int b[MAXN];
int p[MAXN];
int n;


struct node
{
	node *left, *right;
	int lv, rv;
};

node *root;
int t;
node tree[MAXT];

void modify(node *&curr, int l, int r, int L, int R, int v, bool f)
{
	if (r < L || R < l) return;

	if (curr == NULL)
	{
		curr = &(tree[++t]);
		curr->lv = INF;
		curr->rv = INF;
	}

	if (L <= l && r <= R)
	{
		if (f)
			curr->lv = min(curr->lv, v - (l - L));
		else
			curr->rv = min(curr->rv, v + (l - L));
		return;
	}

	int c = (l + r) / 2;

	if (L <= c) modify(curr->left, l, c, L, R, v, f);
	if (c <  R) modify(curr->right, c + 1, r, L, R, v, f);
}


int findmin(node *curr, int l, int r, int x)
{
	if (curr == NULL) return INF;
	if (l == r)
		return min(curr->lv, curr->rv);

	int c = (l + r) / 2;
	int res = 0;
	if (x <= c)
		res = findmin(curr->left, l, c, x);
	else
		res = findmin(curr->right, c + 1, r, x);
	res = min(res, min(curr->lv - (x - l), curr->rv + (x - l)));
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		p[a[i]] = i;


	root = &(tree[0]);
	root->lv = INF;
	root->rv = INF;

	for (int i = 1; i <= n; i++)
	{
		int j = p[b[i]];
		if (i <= j)
		{
			modify(root, 1, n, 1, j - i + 1, j - i, true);
			modify(root, 1, n, j - i + 1, j, 0, false);
			modify(root, 1, n, j + 1, n, n - i, true);
		}
		else
		{
			modify(root, 1, n, 1, j, i - j, false);
			modify(root, 1, n, j + 1, j + n - i + 1, n - i, true);
			modify(root, 1, n, j + n - i + 1, n, 0, false);
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", findmin(root, 1, n, i));

	fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}