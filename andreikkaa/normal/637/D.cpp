#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
const int MAXN = 200 * 1000 + 7;
int x[MAXN];
bool dp[MAXN];
int toJump[MAXN];
struct data
{
	bool state;
	int pos;
	data()
	{
		state = false;
		pos = 0;
	}
	data(bool _state, int _pos)
	{
		state = _state;
		pos = _pos;
	}
};
data merge(data x, data y)
{
	if (x.state) return x;
	return y;
}
struct segmentTree
{
	vector<data>tree;
	segmentTree(int n)
	{
		tree.resize(4 * n + 17);
	}
	void change(int v, int tl, int tr, int pos, bool val)
	{
		if (tl == tr)
		{
			tree[v] = data(val, pos);
		}
		else
		{
			int tm = (tl + tr) / 2;
			if (pos <= tm)
			{
				change(2 * v, tl, tm, pos, val);
			}
			else
			{
				change(2 * v + 1, tm + 1, tr, pos, val);
			}
			tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
		}
	}
	data get(int v, int tl, int tr, int l, int r)
	{
		if (r<tl || l>tr) return data();
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return merge(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
	}
};
void solve(int pos)
{
	if (pos == 1) return;
	solve(toJump[pos]);
	int takeOff = x[toJump[pos] + 1] - 1;
	int startRun = x[toJump[pos]] + 1;
	printf("RUN %d\n", takeOff - startRun);
	printf("JUMP %d\n", x[pos] + 1 - takeOff);
}
int main()
{
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	n++;
	x[1] = -1;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x + 1, x + 1 + n);
	segmentTree st(n);
	dp[1] = true;
	if (x[2] - 1 >= s)
	{
		st.change(1, 1, n, 1, true);
	}	
	for (int i = 2; i <= n; i++)
	{
		int curPos = x[i] + 1;
		int lastCan = curPos - d;
		int lastPoint = lastCan + 1;
		int lastPos = lower_bound(x + 1, x + 1 + n, lastPoint) - x;
		int leftQuery = lastPos;
		if (leftQuery > 1) leftQuery--;
		data tmp = st.get(1, 1, n, leftQuery, i);
		if (!tmp.state) continue;
		dp[i] = true;
		toJump[i] = tmp.pos;
		if (x[i + 1] - x[i] - 2 >= s)
		{
			st.change(1, 1, n, i, true);
		}
	}
	if (!dp[n])
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	solve(n);
	if (m - (x[n] + 1) > 0)
	{
		printf("RUN %d\n", m - (x[n] + 1));
	}
}