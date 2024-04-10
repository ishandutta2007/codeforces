#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	//returns first index such that pref[idx] >= val

	int search(int val)
	{
		int curSum = 0, pos = 0;
		for(int i = log2(N) + 1; i >= 0; i--)
		{
			if(pos + (1 << i) < N && curSum + bit[pos + (1 << i)] < val)
			{
				curSum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int nC2(int n)
{
	return n * (n - 1) / 2;
}

int n, m, k;
int x[N], y[N];
map<int, vector<int> > xs, ys;
pair<int, int> loc[N];
BIT bit;

int get(map<int, vector<int> > &x, map<int, vector<int> > &y)
{
	vector<pair<int, int> > v;
	for(auto &it:x)
	{
		for(auto &j:it.second)
			v.push_back({j, it.first});
	}
	sort(v.begin(), v.end());
	y[-1];
	y[1e6 + 4];
	int idx = -1;
	int ans = 0;
	for(auto &it:y)
	{
		map<int, int> m;
		while(idx + 1 < v.size() && v[idx + 1].first < it.first)
		{
			int y = v[idx + 1].first;
			//ans += bit.rsum(1, 1e6 + 3) - bit.rsum(y, y);
			m[v[idx + 1].second] += 1;
			bit.update(v[idx + 1].second, 1);
			idx++;
		}
		for(auto &it:m)
			ans += it.second * (bit.rsum(1, 1e6 + 3) - bit.rsum(it.first, it.first));
		for(auto &it:m)
			bit.update(it.first, -it.second);
	}
	return ans / 2;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	bit.init(1e6 + 5);
	while(t--)
	{
		cin >> n >> m >> k;
		xs.clear();
		ys.clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
			x[i]++;
			xs[x[i]];
		}
		for(int i = 1; i <= m; i++)
		{
			cin >> y[i];
			y[i]++;
			ys[y[i]];
		}
		for(int i = 1; i <= k; i++)
		{
			cin >> loc[i].first >> loc[i].second;
			loc[i].first++;
			loc[i].second++;
			int curx = loc[i].first;
			int cury = loc[i].second;
			if(xs.count(curx) && ys.count(cury))
				continue;
			else if(xs.count(curx))
				xs[curx].push_back(cury);
			else
				ys[cury].push_back(curx);
		}
		int ans = 0;
		ans += get(xs, ys);
		ans += get(ys, xs);
		cout << ans << endl;
	}
	return 0;
}