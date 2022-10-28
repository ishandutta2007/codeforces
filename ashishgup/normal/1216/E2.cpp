//Forgot to register

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int last[N], len[N], cnt[N], pw10[N], pref[N];

int get(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans++;
		x /= 10;
	}
	return ans;
}

void work()
{
	last[0] = 0;
	len[0] = 0;
	cnt[0] = 0;
	pw10[0] = 1;
	for(int i = 1; i <= 18; i++)
		pw10[i] = pw10[i - 1] * 10;
	for(int i = 1; i <= 18; i++)
	{
		cnt[i] = pw10[i] - 1;
		for(int j = 0; j <= i - 1; j++)
			cnt[i] -= cnt[j];
		len[i] = min(2e18l, 1.0l * last[i - 1] * cnt[i] + 1.0l * i * (cnt[i] * (cnt[i] + 1)) / 2);
		pref[i] = pref[i - 1] + len[i];
		pref[i] = min(1.0l * pref[i], 2e18l);
		last[i] = last[i - 1] + cnt[i] * i;
	}
}

int k;

int check(int idx, int mid)
{
	int left = k - pref[idx - 1];
	left -= min(2e18l, 1.0l * last[idx - 1] * (mid - 1));
	if(left <= 0)
		return 0;
	left -= min(2e18l, 1.0l * (mid - 1) * mid * idx / 2);
	if(left <= 0)
		return 0;
	return 1;
}

int get2(int x, int y)
{
	vector<int> v;
	while(x > 0)
	{
		v.push_back(x % 10);
		x /= 10;
	}
	reverse(v.begin(), v.end());
	return v[y - 1];
}

int getd(int idx)
{
	for(int i = 1; i <= 18; i++)
	{
		if(idx / i > cnt[i])
		{
			idx -= cnt[i] * i;
		}
		else
		{
			int x = cnt[i] * i;
			if(idx > x)
				idx -= x;
			else
			{
				int take = (idx - 1) / i;
				int elem = pw10[i - 1] + take;
				idx -= take * i;
				return get2(elem, idx);
			}
		}
	}
}

int32_t main()
{
	IOS;
	work();
	int q;
	cin >> q;
	while(q--)
	{
		cin >> k;
		for(int i = 1; i <= 18; i++)
		{
			if(k <= pref[i])
			{
				int lo = 1, hi = cnt[i];
				while(lo < hi)
				{
					int mid = (lo + hi + 1) / 2;
					if(check(i, mid))
						lo = mid;
					else
						hi = mid - 1;
				}
				int idx = k - pref[i - 1] - last[i - 1] * (lo - 1);
				idx -= (lo - 1) * lo * i / 2;
				cout << getd(idx) << endl;
				break;
			}
		}
	}
	return 0;
}