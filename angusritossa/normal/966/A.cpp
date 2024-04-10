#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, v;
int stairs[1000010], elev[1000010];
set<int> st, ele;
int dostairs(int x1, int y1, int x2, int y2)
{
	if (y2 > n) return 1e9;
	int d = abs(y1-y2);
	if (x1 > x2) swap(x1, x2);
	int ans2 = 1e9;
	if (y1 == y2) ans2 = abs(x1-x2);
	auto it = st.lower_bound(x1);
	if (it != st.end())
	{
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	if (it != st.begin())
	{
		it--;
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	it = st.lower_bound(x2);
	if (it != st.end())
	{
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	return d + ans2;
}
int doele(int x1, int y1, int x2, int y2)
{
	if (y2 > n) return 1e9;
	int d = abs(y1-y2)/v;
	if (abs(y1-y2) % v) d++;
	if (x1 > x2) swap(x1, x2);
	int ans2 = 1e9;
	if (y1 == y2) ans2 = abs(x1-x2);
	auto it = ele.lower_bound(x1);
	if (it != ele.end())
	{
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	if (it != ele.begin())
	{
		it--;
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	it = ele.lower_bound(x2);
	if (it != ele.end())
	{
		int am = abs(*it - x1) + abs(*it - x2);
		ans2 = min(ans2, am);
	}
	return d + ans2;
}
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &s, &e, &v);
	for (int i = 0; i < s; i++)
	{
		scanf("%d", &stairs[i]);
		st.insert(stairs[i]);
	}
	for (int i = 0; i < e; i++)
	{
		scanf("%d", &elev[i]);
		ele.insert(elev[i]);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		int ans = 1e9;
		if (st.size()) ans = min(ans, dostairs(x1, y1, x2, y2));
		if (ele.size()) ans = min(ans, doele(x1, y1, x2, y2));
		printf("%d\n", ans);
	}
}