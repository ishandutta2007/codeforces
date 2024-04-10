#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define left(i) ((i)<<1)
#define right(i) (((i)<<1)+1)

struct query{
	int l, r, val, id;
	query(){}
	query(int a, int b, int c, int d) : l(a), r(b), val(c), id(d) {}
	bool operator < (query x) const{
		return val < x.val;
	}
} q[112345];

pair<int,int> a[112345];
int val[412345];
int ans[112345];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int sum(int a, int b)
{
	return a + b;
}

void change(int id, int l, int r, int a, int x, int join(int, int))
{
	if(l == r)
		val[id] += x;
	else
	{
		int mid = (l+r)/2;
		if(a <= mid)
			change(left(id), l, mid, a, x, join);
		else
			change(right(id), mid+1, r, a, x, join);
		val[id] = join(val[right(id)], val[left(id)]);
	}
}

int get(int id, int l, int r, int a, int b, int (*join)(int, int))
{
	if(l == a && r == b)
		return val[id];
	else
	{
		int mid = (l+r)/2;
		if(b <= mid)
			return get(left(id), l, mid, a, b, *join);
		else if(a >= mid + 1)
			return get(right(id), mid+1, r, a, b, *join);
		else
			return (*join)(get(left(id), l, mid, a, mid, *join), get(right(id), mid+1, r, mid+1, b, *join));
	}
}

int main(void)
{
	int n, m, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; a[i].second = i, i++)
	{
		scanf("%d", &a[i].first);
		change(1, 1, n, i, a[i].first, gcd);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; q[i].val = get(1, 1, n, q[i].l, q[i].r, gcd), q[i].id = i, i++)
		scanf("%d %d", &q[i].l, &q[i].r);
	sort(a+1, a+n+1);
	sort(q, q+m);
	int in = 0, out = 0;
	memset(val, 0, sizeof(val));
	for(int i = 0; i < m; i++)
	{
		for(int j = in + 1; j <= n && a[j].first <= q[i].val; in = j++)
			change(1, 1, n, a[j].second, 1, sum);
		for(int j = out + 1; j <= n && a[j].first < q[i].val; out = j++)
			change(1, 1, n, a[j].second, -1, sum);
		ans[q[i].id] = q[i].r - q[i].l + 1 - get(1, 1, n, q[i].l, q[i].r, sum);
	}
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}