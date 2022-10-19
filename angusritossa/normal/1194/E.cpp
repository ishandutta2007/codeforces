#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int n;
int x1[5010], x2[5010], Y1[5010], y2[5010];
vector<array<int, 3> > hor, ver;
bool inter[5010][5010];
int bit[10010];
int query(int a)
{
	int ans = 0;
	while (a)
	{
		ans+=bit[a];
		a-=a&-a;
	}
	return ans;
}
void update(int a, int val)
{
	while (a < 10010)
	{
		bit[a]+=val;
		a+=a&-a;
	}
}
ll ans;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &x1[i], &Y1[i], &x2[i], &y2[i]);
		x1[i] += 5001, x2[i] += 5001, Y1[i] += 5001, y2[i] += 5001;
		if (x1[i] == x2[i])
		{
			hor.push_back({x1[i], min(Y1[i], y2[i]), max(Y1[i], y2[i])});
		}
		else
		{
			ver.push_back({Y1[i], min(x1[i], x2[i]), max(x1[i], x2[i])});
		}
	}
	if (hor.size() > ver.size()) swap(hor, ver);
	sort(hor.begin(), hor.end());
	for (int i = 0; i < hor.size(); i++)
	{
		for (int j = 0; j < ver.size(); j++)
		{
			if (hor[i][1] <= ver[j][0] && ver[j][0] <= hor[i][2] &&
				ver[j][1] <= hor[i][0] && hor[i][0] <= ver[j][2])
			{
				inter[i][j] = 1;
				D("inter %d %d\n", i, j);
			}
		}
	}
	for (int i = 0; i < hor.size(); i++)
	{
		fill_n(bit, 10010, 0);
		vector<pair<int, int> > ends;
		for (int j = 0; j < ver.size(); j++)
		{
			if (inter[i][j])
			{
				ends.emplace_back(ver[j][2], ver[j][0]);
				update(ver[j][0], 1);
			}
		}
		sort(ends.begin(), ends.end());
		int k = 0;
		for (int j = i+1; j < hor.size(); j++)
		{
			while (k < ends.size() && ends[k].first < hor[j][0])
			{
				update(ends[k].second, -1);
				k++;
			}
			ll am = query(hor[j][2]);
			am -= query(hor[j][1]-1);
			ans += (am*(am-1ll))/2ll;
		}
	}
	printf("%lld\n", ans);
}