#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2005;

int n, p;
int a[N], f[2 * N];
int cache[2 * N][N];

int dp(int cur, int killed)
{
	if(killed == n)
		return 1;
	int &ans = cache[cur][killed];
	if(ans != -1)
		return ans;
	ans = 0;
	int tot = f[cur] - killed;
	ans = tot * dp(cur + 1, killed + 1);
	ans %= p;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = 1; i <= 4000; i++)
		f[i] += f[i - 1];
	vector<int> ans;
	for(int x = 1; x <= 2000; x++)
		if(dp(x, 0))
			ans.push_back(x);
	cout << ans.size() << endl;
	for(auto &it:ans)
		cout << it << " ";
	cout << endl;
	return 0;
}