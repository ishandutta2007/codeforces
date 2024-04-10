#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e5 + 5;
const int M = 50;
 
int n, m, idx = 0, ans = 0;
int t[N], a[N];
int dp[1 << 20], mx[1 << 20], dp2[1 << 20], take[1 << 20];
string s[N];
int mask[M];
map<string, int> comp;
bool mark[M][M];
 
void brute(int sz)
{
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)	
		{
			if(i == j)
				continue;
			if(mark[i][j])
				mask[i] |= (1 << j);
		}
	}
	for(int i = 1; i < (1 << sz); i++)
	{
		bool flag = 1;
		for(int j = 0; j < sz; j++)
		{
			if(i >> j & 1)
			{
				if((mask[j] & i) > 0)
				{
					flag = 0;
					break;
				}
			}
		}	
		if(!flag)
			continue;
		dp[i] = __builtin_popcount(i);
		ans = max(ans, dp[i]);
	}
}
 
void sos(int sz)
{
	for(int i = 0; i < sz; i++)	
	{
		for(int mask = 0; mask < (1 << sz); mask++)
		{
			if(mask >> i & 1)
			{
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
			}
		}
	}
}
 
void other(int sz)
{
	int off = (m + 1) / 2;
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)	
		{
			if(i == j)
				continue;
			if(mark[off + i][off + j])
				mask[off + i] |= (1 << j);
		}
	}
	for(int i = 0; i < sz; i++)
	{
		take[i] = (1 << off) - 1;
		for(int j = 0; j < (m + 1) / 2; j++)
		{
			if(mark[off + i][j])
				take[i] ^= (1 << j);
		}
	}
	for(int i = 1; i < (1 << sz); i++)
	{
		bool flag = 1;
		int otherM = (1 << off) - 1;
		for(int j = 0; j < sz; j++)
		{
			if(i >> j & 1)
			{
				otherM &= take[j];
				if((mask[off + j] & i) > 0)
				{
					flag = 0;
					break;
				}
			}
		}	
		if(!flag)
			continue;
		dp2[i] = __builtin_popcount(i);
		ans = max(ans, dp2[i]);
		ans = max(ans, dp2[i] + dp[otherM]);
	}
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i];
		if(t[i] == 2)
		{
			cin >> s[i];
			comp[s[i]];
		}
	}
	for(auto &it:comp)
		it.second = idx++;
	for(int i = 1; i <= n; i++)
	{
		if(t[i] == 2)
			a[i] = comp[s[i]];
	}
	for(int i = 1; i <= n; i++)
	{
		if(t[i] == 1)
			continue;
		int j = i;
		set<int> s;
		s.insert(a[i]);
		while(j + 1 <= n && t[j + 1] == t[i])
		{
			j++;
			s.insert(a[j]);
		}
		vector<int> v;
		for(auto &it:s)
			v.push_back(it);
		for(int i = 0; i < v.size(); i++)
		{
			for(int j = i + 1; j < v.size(); j++)
			{
				int nu = v[i], nv = v[j];
				mark[nu][nv] = mark[nv][nu] = 1;
			}
		}
		i = j;
	}
	brute((m + 1) / 2);
	sos((m + 1) / 2);
	other(m / 2);
	cout << ans;
	return 0;
}