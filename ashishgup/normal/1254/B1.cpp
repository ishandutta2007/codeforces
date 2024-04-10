#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, sum = 0;
int a[N];

int get(int lcnt, int rcnt, int lsum, int rsum, int median)
{
	int moves = rsum - rcnt * median + lcnt * median - lsum;
	return moves;
}

int cost(vector<pair<int, int> > &v) // {idx, value}
{
	int lcnt = 0, rcnt = 0, lsum = 0, rsum = 0;
	for(auto &it:v)
	{
		rcnt += it.second;
		rsum += (it.first * it.second);
	}
	int cur = 2e18;
	for(int i = 0; i < v.size(); i++)
	{
		cur = min(cur, get(lcnt, rcnt, lsum, rsum, v[i].first));
		lcnt += v[i].second;
		lsum += v[i].first * v[i].second;
		rcnt -= v[i].second;
		rsum -= v[i].first * v[i].second;
	}
	return cur;
}

int get(int x)
{
	int cur = 0, cnt = 0;
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i++)
	{
		if(cnt + a[i] >= x)
		{
			int take = x - cnt;
			v.push_back({i, take});
			cur += cost(v);
			v.clear();
			if((a[i] - take) % x > 0)
			{
				cnt = (a[i] - take) % x;
				v.push_back({i, (a[i] - take) % x});
			}
			else
				cnt = 0;
		}
		else
		{
			cnt += a[i];
			v.push_back({i, a[i]});
		}
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if(sum == 1)
	{
		cout << -1;
		return 0;
	}
	int ans = 2e18;
	for(int i = 2; i * i <= sum; i++)
	{
		if(sum % i == 0)
		{
			ans = min(ans, get(i));
			ans = min(ans, get(sum / i));
		}
	}
	ans = min(ans, get(sum));
	cout << ans;
	return 0;
}