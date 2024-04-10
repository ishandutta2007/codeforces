#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

class segmentTree
{
private:
	const int nullValue = 0;
	struct node
	{
		ll v;
		int l, r;
		ll hold = 0;
		node(ll value, int left, int right)
		{
			v = value;
			l = left;
			r = right;
		}
		node()
		{
			v = -1;
			l = -1;
			r = -1;
		}
	};
	node tree[524288];
	ll arr[200000];
	int size;

	int parent(int n) { return (n - 1) / 2; }
	int left(int n) { return 2 * n + 1; }
	int right(int n) { return 2 * n + 2; }

	ll merge(ll a, ll b)
	{
		return a < b ? a : b;
	}
	ll create(int n, int l, int r)
	{
		if (l == r)
			tree[n] = node(arr[l], l, r);
		else
		{
			tree[n] = node(
				merge(create(left(n), l, (l + r) / 2),
					create(right(n), (l + r) / 2 + 1, r))
				, l, r);
		}
		return tree[n].v;
	}
	ll getValue(int n, int l, int r)
	{
		if (tree[n].r < l || tree[n].l > r)
			return nullValue;
		else if (tree[n].l >= l && tree[n].r <= r)
			return tree[n].v;
		else
		{
			if (tree[n].hold)
			{
				tree[left(n)].v += tree[n].hold;
				tree[right(n)].v += tree[n].hold;
				tree[left(n)].hold += tree[n].hold;
				tree[right(n)].hold += tree[n].hold;
				tree[n].hold = 0;
			}
			return merge(getValue(left(n), l, r),
				getValue(right(n), l, r));
		}
	}
	void update(int n,int l,int r,ll v)
	{
		if (tree[n].r < l || tree[n].l > r)
			return;
		else if (tree[n].l >= l && tree[n].r <= r)
		{
			tree[n].v += v;
			tree[n].hold += v;
		}
		else
		{
			if (tree[n].hold)
			{
				tree[left(n)].v += tree[n].hold;
				tree[right(n)].v += tree[n].hold;
				tree[left(n)].hold += tree[n].hold;
				tree[right(n)].hold += tree[n].hold;
				tree[n].hold = 0;
			}
			update(left(n), l, r, v);
			update(right(n), l, r, v);
			tree[n].v = merge(tree[left(n)].v, tree[right(n)].v);
		}
	}
public:
	void Create(ll* a, int s)
	{
		size = s;
		for (int i = 0; i < size; i++)
			arr[i] = a[i];
		create(0, 0, size - 1);
	}
	ll GetValue()
	{
		return getValue(0, 0, size - 1);
	}
	ll GetValue(int l, int r)
	{
		return getValue(0, l, r);
	}
	void Update(int l,int r,ll v)
	{
		if(r >= l)
			update(0, l, r, v);
	}
};

int main()
{
	int n;
	cin >> n;
	int pos[200000];
	int v[200000];
	ll S[200000];
	Loop(i, 0, n)
	{
		int x;
		cin >> x; x--;
		pos[x] = i;
	}
	cin >> v[0];
	S[0] = v[0];
	Loop(i, 1, n)
	{
		cin >> v[i];
		S[i] = S[i - 1] + v[i];
	}
	segmentTree T;
	T.Create(S, n - 1);
	ll ans = T.GetValue();
	
	Loop(i, 0, n)
	{
		int p = pos[i];
		T.Update(0, p - 1, v[p]);
		T.Update(p, n - 2, -v[p]);
		ll x = T.GetValue();
		if (x < ans)
			ans = x;
	}

	cout << ans;
}