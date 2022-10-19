#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int val, l, r;
	bool lazyval, lazy;
};
Node rangetree[15000000];
int upto;
void push(int curr, int cstart, int cend)
{
	int mid = (cstart+cend)/2;
	int sz1 = mid-cstart+1;
	int sz2 = cend-mid;
	if (!rangetree[curr].lazy) return;
	int lazyval = rangetree[curr].lazyval;
	rangetree[rangetree[curr].l].val = sz1*lazyval;
	rangetree[rangetree[curr].r].val = sz2*lazyval;
	rangetree[rangetree[curr].l].lazyval = lazyval;
	rangetree[rangetree[curr].r].lazyval = lazyval;
	rangetree[rangetree[curr].l].lazy = true;
	rangetree[rangetree[curr].r].lazy = true;
	rangetree[curr].lazy = rangetree[0].val = 0;
}
void update(int s, int e, int val, int curr = 1, int cstart = 0, int cend = 1000000010)
{
	if (s <= cstart && cend <= e)
	{
		rangetree[curr].val = (cend-cstart+1)*val;
	//	printf("%d %d %d\n", cstart, cend, rangetree[curr].val);
		rangetree[curr].lazyval = val;
		rangetree[curr].lazy = true;
		return;
	}
	if (!rangetree[curr].l) rangetree[curr].l = ++upto;
	if (!rangetree[curr].r) rangetree[curr].r = ++upto;
	push(curr, cstart, cend);
	int mid = (cstart+cend)/2;
	if (e <= mid) update(s, e, val, rangetree[curr].l, cstart, mid);
	else if (s > mid) update(s, e, val, rangetree[curr].r, mid+1, cend);
	else
	{
		update(s, e, val, rangetree[curr].l, cstart, mid);
		update(s, e, val, rangetree[curr].r, mid+1, cend);
	}
	//printf("%d %d %d %d\n", cstart, cend, rangetree[rangetree[curr].l].val, rangetree[rangetree[curr].r].val);
	rangetree[curr].val = rangetree[rangetree[curr].l].val + rangetree[rangetree[curr].r].val;
}
int main()
{
	int n;
	upto++;
	scanf("%d", &n);
	update(1, n, 1);
	int q;
	scanf("%d", &q);
//	printf("%d\n", rangetree[1].val);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int v;
		scanf("%d", &v);
		v--;
		update(l, r, v);
		printf("%d\n", rangetree[1].val);
	//	return 0;
	}

}