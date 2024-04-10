#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 5;
const int P = 7;

int n, p, k;

struct data
{
	int a;
	int s[P];
};

bool comp(data &d1, data &d2)
{
	return d1.a > d2.a;
}

int idx;

bool comp2(data &d1, data &d2)
{
	return d1.s[idx] < d2.s[idx];
}

data st[N];
int lsz, rsz;
long long lsum;
vector<data> l, r;
bool visL[N][1 << P], visR[105][P][1 << P];
long long cacheL[N][1 << P], cacheR[105][P][1 << P];

long long dpL(int i, int mask)
{
	if(mask == 0)
		return 0;
	if(i == lsz)
		return -1e18;
	long long &ans = cacheL[i][mask];
	if(visL[i][mask])
		return ans;
	ans = dpL(i + 1, mask);
	visL[i][mask] = 1;
	for(int j = 0; j < p; j++)
	{
		if(mask >> j & 1)
		{
			int nMask = (mask & ~(1 << j));
			ans = max(ans, l[i].s[j] - l[i].a + dpL(i + 1, nMask));
		}
	}
	return ans;
}

long long dpR(int i, int take, int mask)
{
	if(mask == 0 && take == 0)
		return 0;
	if(i == rsz)
		return -1e18;
	long long &ans = cacheR[i][take][mask];
	if(visR[i][take][mask])
		return ans;
	ans = dpR(i + 1, take, mask);
	visR[i][take][mask] = 1;
	if(take > 0)
		ans = max(ans, r[i].a + dpR(i + 1, take - 1, mask));
	for(int j = 0; j < p; j++)
	{
		if(mask >> j & 1)
		{
			int nMask = (mask & ~(1 << j));
			ans = max(ans, r[i].s[j] + dpR(i + 1, take, nMask));
		}
	}
	return ans;
}

long long getLeft(int mask)
{
	return dpL(0, mask);
}

long long getRight(int mask)
{
	int take = 0;
	int curMask = 0;
	for(int i = 0; i < p; i++)
	{
		if(mask >> i & 1)
			take++;
		else
			curMask |= (1 << i);
	}
	return dpR(0, take, curMask);
}

int32_t main()
{
	IOS;
	memset(cacheL, -1, sizeof(cacheL));
	memset(cacheR, -1, sizeof(cacheR));
	cin >> n >> p >> k;
	for(int i = 0; i < n; i++)
		cin >> st[i].a;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < p; j++)
			cin >> st[i].s[j];
	sort(st, st + n, comp);
	for(int i = 0; i < k; i++)
	{
		lsum += st[i].a;
		l.push_back(st[i]);
	}
	vector<data> temp;
	for(int i = k; i < n; i++)
		temp.push_back(st[i]);
	if(temp.size() > 100)
	{
		for(int i = 0; i <= p; i ++)
			r.push_back(temp[i]);
		reverse(temp.begin(), temp.end());
		for(int i = 0; i <= p; i++)
			temp.pop_back();
		for(int i = 0; i < p; i++)
		{
			idx = i;
			sort(temp.begin(), temp.end(), comp2);
			for(int j = 0; j <= p; j++)
			{
				r.push_back(temp.back());
				temp.pop_back();
			}
		}
	}
	else
		r = temp;
	lsz = l.size();
	rsz = r.size();
	long long ans = 0;
	for(int mask = 0; mask < (1 << p); mask++)
	{
		if(__builtin_popcount(mask) > l.size())
			continue;
		ans = max(ans, lsum + getLeft(mask) + getRight(mask));
	}
	cout << ans;
	return 0;
}