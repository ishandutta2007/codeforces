#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll val;
	int left, right;
};
Node rangetree[10000010];
int upto;
void update(ll node, ll val, int curr = 1, ll cstart = 0, ll cend = (1ll << 60)-1)
{
	if (cstart == cend)
	{
		rangetree[curr].val+=val;
		return;
	}
	ll mid = (cstart+cend)/2;
	if (node <= mid)
	{
		if (!rangetree[curr].left) rangetree[curr].left = ++upto;
		update(node, val, rangetree[curr].left, cstart, mid);
	}
	else
	{
		if (!rangetree[curr].right) rangetree[curr].right = ++upto;
		update(node, val, rangetree[curr].right, mid+1, cend);
	}
	rangetree[curr].val = rangetree[rangetree[curr].left].val + rangetree[rangetree[curr].right].val; 
}
ll xored, pre;
ll query(int curr = 1, ll bit = 59, ll cstart = 0, ll cend = (1ll << 60)-1)
{
	if (cstart == cend) 
	{
		if ((cstart^xored) <= pre) return 0;
		return cstart;
	}
	ll mid = (cstart+cend)/2;
	ll newxor = xored;
	newxor &= ~((1ll << (bit+1))-1);
	if ((cend ^ newxor) <= pre) return 0;
	if (xored & (1ll << bit))
	{
		// do opposite
		if (rangetree[rangetree[curr].right].val)  
		{
			ll a = query(rangetree[curr].right, bit-1, mid+1, cend);
			if (a) return a;
 		}
		if (rangetree[rangetree[curr].left].val) 
		{
			ll a = query(rangetree[curr].left, bit-1, cstart, mid);
			if (a) return a;
		}
	}
	else
	{
		if (rangetree[rangetree[curr].left].val) 
		{
			ll a = query(rangetree[curr].left, bit-1, cstart, mid);
			if (a) return a;
		}
		if (rangetree[rangetree[curr].right].val) 
		{
			ll a = query(rangetree[curr].right, bit-1, mid+1, cend);
			if (a) return a;
		}
	}
	return 0;
}
int n;
ll ans[100010], a[100010];
ll ans2[100010];
int main()
{
	scanf("%d", &n);
	upto++;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		update(a[i], 1);
	}
	for (int i = 0; i < n; i++)
	{
		ll val = query();
		ans[i] = val;
		ans2[i] = val ^ xored;
		pre = ans2[i];
		if (i)
		{
			if (ans2[i] <= ans2[i-1] || !pre)
			{
				printf("No\n");
				return 0;
			}
		}
		update(val, -1);
		xored ^= val;
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++) printf("%I64d ", ans[i]);
	printf("\n");
}