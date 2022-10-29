#include <stdio.h>
#include <map>
#include <set>
#include <string.h>
using namespace std;

#define inf 0x3f3f3f3f
#define left(i) ((i)<<1)
#define right(i) (((i)<<1)+1)

int val1[812345], val2[812345];
int a[212345], b[212345], tp[212345];
int pos[212345], lpos;
set<int> been;

void insert(int val[], int id, int l, int r, int pos, int x)
{
	if(l == r)
		val[id] = x;
	else
	{
		int mid = (l + r)/2;
		if(pos <= mid)
			insert(val, left(id), l, mid, pos, x);
		else
			insert(val, right(id), mid+1, r, pos, x);
		val[id] = min(val[left(id)], val[right(id)]);
	}
}

int query(int val[], int id, int l, int r, int a, int b)
{
	if(l == a && r == b)
		return val[id];
	else
	{
		int mid = (l+r)/2;
		if(b <= mid)
			return query(val, left(id), l, mid, a, b);
		else if(a > mid)
			return query(val, right(id), mid+1, r, a, b);
		else
			return min(query(val, left(id), l, mid, a, mid), query(val, right(id), mid+1, r, mid+1, b));
	}
}

int
main(void)
{
	int n, q;
	char c;
	scanf("%d %d", &n, &q);
	memset(val1, 0x3f, sizeof(val2));
	memset(val2, 0x3f, sizeof(val2));
	map<int,int> rdm;
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d %c", &a[i], &b[i], &c);
		tp[i] = (c == 'U');
		rdm[a[i]] = i + 1;
	}
	for(map<int,int>:: iterator it = rdm.begin(); it != rdm.end(); it++)
	{
		it->second = lpos;
		pos[lpos++] = it->first;
	}

	for(int i = 0; i < q; i++)
	{
		if(been.find(a[i]) != been.end())
		{
			printf("0\n");
			continue;
		}
		been.insert(a[i]);
		if(tp[i] == 0)
		{
			int y = rdm[a[i]];
			int bot = 0, top = rdm[a[i]];
			int x = -1;
			while(bot <= top)
			{
				int mid = (bot + top)/2;
				if(query(val1, 1, 0, lpos - 1, mid, y) <= b[i])
				{
					x = mid; bot = mid + 1;
				}
				else
				{
					top = mid - 1;
				}
			}
			if(x == -1)
			{
				printf("%d\n", a[i]);
				insert(val2, 1, 0, lpos - 1, y, 1);
			}
			else
			{
//				printf("%d %d %d ", i, pos[x], a[i]);
				printf("%d\n", a[i] - pos[x]);
				insert(val2, 1, 0, lpos - 1, y, pos[x] + 1);
			}
		}
		else
		{
			int y = rdm[a[i]];
			int bot = rdm[a[i]], top = lpos - 1;
			int x = -1;
			while(bot <= top)
			{
				int mid = (bot + top)/2;
				if(query(val2, 1, 0, lpos - 1, y, mid) <= a[i])
				{
					x = mid; top = mid - 1;
				}
				else
				{
					bot = mid + 1;
				}
			}
			if(x == -1)
			{
				printf("%d\n", b[i]);
				insert(val1, 1, 0, lpos - 1, y, 1);
			}
			else
			{
				printf("%d\n", pos[x] - a[i]);
				insert(val1, 1, 0, lpos - 1, y, b[i] - (pos[x] - a[i]) + 1);
			}
		}

	}

}