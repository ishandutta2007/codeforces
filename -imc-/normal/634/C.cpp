#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segtree
{
	int n;
	vector<int> a;
	vector<int> tree;
	int maxValue;
	
	segtree(int n, int maxValue): n(n), a(n), tree(n * 4), maxValue(maxValue) {}
	
	void add(int index, int value)
	{
		change(index, min(maxValue, a[index] + value));
	}
	
	void change(int index, int value)
	{
		//printf("%d is now %d\n", index, value);
		a[index] = value;
		change(0, 0, n - 1, index, value);
	}
	
	void change(int t, int l, int r, int index, int value)
	{
		if (l == r)
			return void(tree[t] = value);
		
		int m = (l + r) / 2;
		if (index <= m)
			change(t * 2 + 1, l, m, index, value);
		else
			change(t * 2 + 2, m + 1, r, index, value);
		
		tree[t] = tree[t * 2 + 1] + tree[t * 2 + 2];
	}
	
	int query(int l, int r)
	{
		return query(0, 0, n - 1, l, r);
	}
	
	int query(int t, int l, int r, int x, int y)
	{
		if (x > y) return 0;
		if (x > r || y < l) return 0;
		
		if (l >= x && r <= y)
			return tree[t];
		
		int m = (l + r) / 2;
		return query(t * 2 + 1, l, m, x, y) + query(t * 2 + 2, m + 1, r, x, y);
	}
};

int main()
{
	int n, k, a, b, q;
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
	
	segtree prefix(n, b), suffix(n, a);
	
	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d", &type);
		
		if (type == 1)
		{
			// add
			int day, add;
			scanf("%d %d", &day, &add);
			day--;
			
			prefix.add(day, add);
			suffix.add(day, add);
		}
		else
		{
			// query
			int p;
			scanf("%d", &p);
			p--;
			
			int answer = prefix.query(0, p - 1) + suffix.query(p + k, n - 1);
			//printf("%d %d\n", prefix.query(0, p - 1), suffix.query(p + k, n - 1));
			printf("%d\n", answer);
		}
	}
	
	return 0;
}