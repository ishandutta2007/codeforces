//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n;
int a[N], f[N];
vector<int> primes[N];

void precompute()
{
	for(int i = 2; i < N; i++)
	{
		if(primes[i].size() == 0)
		{
			for(int j = 1; i * j < N; j++)
				primes[i * j].push_back(i);
		}
	}
}

int cache[N];

int dp(int val)
{
	int &ans = cache[val];
	if(ans != -1)
		return ans;
	ans = f[val];
	for(auto &it:primes[val])
		ans = max(ans, f[val] + dp(val / it));
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		memset(f, 0, sizeof(f));
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			f[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		int ans = 0;
		for(int i = 1; i <= 2e5; i++)
			ans = max(ans, dp(i));
		cout << n - ans << endl;
	}
	return 0;
}