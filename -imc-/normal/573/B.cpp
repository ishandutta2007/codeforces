#include <stdio.h>
#include <assert.h>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> h;
int n;

struct some
{	
	vector<int> tree;
	
	some(): tree(n * 4, INF) {}
	
	void assign(int l, int r, int value)
	{
		if (l < 0) l = 0;
		if (r >= n) r = n - 1;
		assert((r - l) >= 0);
		assign(0, 0, n - 1, l, r, value);
	}
	
	void assign(int t, int l, int r, int x, int y, int value)
	{
		if (x > r || y < l) return;
		
		if (l >= x && r <= y)
		{
			tree[t] = min(tree[t], value);
			return;
		}
		
		int m = (l + r) / 2;
		
		assign(t * 2 + 1, l, m, x, y, value);
		assign(t * 2 + 2, m + 1, r, x, y, value);
	}
	
	vector<int> getMin()
	{
		vector<int> x(n);
		getMin(0, 0, n - 1, INF, x);
		return x;
	}
	
	void getMin(int t, int l, int r, int cur, vector<int>& to)
	{
		if (l == r)
		{
			to[l] = min(cur, tree[t]);
			return;
		}
		
		int m = (l + r) / 2;
		getMin(t * 2 + 1, l, m, min(cur, tree[t]), to);
		getMin(t * 2 + 2, m + 1, r, min(cur, tree[t]), to);
	}
};

bool ok(int t)
{
	some inc, dec;
	
	for (int i = 0; i < n; i++)
	{
		inc.assign(i, i + t, h[i] - t - i);
		dec.assign(i - t, i, h[i] - t + i);
	}
	
	vector<int> a = inc.getMin(), b = dec.getMin();
	
	/*for (int i = 0; i < n; i++)
	{
		int hh = min(a[i] + i, b[i] - i);
		printf("%d ", hh);
	}
	printf("\n");*/
	
	for (int i = 0; i < n; i++)
	{
		int hh = min(a[i] + i, b[i] - i);
		if (hh > 0)
			return false;
	}
	
	return true;
}

int main()
{
	scanf("%d", &n);
	n += 2;
	
	h.resize(n);
	for (int i = 0; i < n - 2; i++)
		scanf("%d", &h[i + 1]);
	
	/*for (int i = 0; i < n; i++)
	{
		printf("moves: %d\n", i);
		ok(i);
	}*/
	
	int low = 0, high = n;
	while (low != high)
	{
		int m = (low + high) / 2;
		
		if (ok(m))
			high = m;
		else
			low = m + 1;
	}
	
	printf("%d\n", low);
	
	return 0;
}