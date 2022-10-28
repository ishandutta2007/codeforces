#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, k, sz;
string s;
int cache[N][3];
vector<int> v;

int dp(int idx, int cur)
{
	if(idx >= sz)
		return 0;
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	if(cur == 0)
	{
		int cur1 = v[idx] + dp(idx + 1, 0);
		int cur2 = (!v[idx]) + dp(idx + 1, 1);
		ans = min(cur1, cur2);
	}
	else if(cur == 1)
	{
		int cur1 = v[idx] + dp(idx + 1, 2);
		int cur2 = (!v[idx]) + dp(idx + 1, 1);
		ans = min(cur1, cur2);
	}
	else
	{
		ans = v[idx] + dp(idx + 1, 2);
	}
	return ans;
}

int get(vector<int> &v)
{
	sz = v.size();
	for(int i = 0; i <= sz; i++)
		cache[i][0] = cache[i][1] = cache[i][2] = -1;
	return dp(0, 0);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		int total = 0;
		for(auto &it:s)
			total += (it - '0');
		int ans = n;
		for(int i = 0; i < k; i++)
		{
			v.clear();
			for(int j = i; j < n; j += k)
				v.push_back(s[j] - '0');
			int on = 0;
			for(auto &it:v)
				on += it;
			int cur = (total - on);
			cur += get(v);
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}	
	return 0;
}