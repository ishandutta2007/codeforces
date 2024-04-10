#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int dis[30];
int dis2[30][30];
pair<int, int> a[30];
int dp[50000005];   
int par[50000005];
int pow2[30];  
int get(int n, int i)
{
	return (n >> i) & 1;
} 
int main()
{
	int n, x, y;
	long long ans = 0;
	cin >> x;
	cin >> y;
	cin >> n;
	for(int i = 0; i < n ; i ++)
	{
		cin >> a[i].first;
		cin >> a[i].second;
		dis[i] = (a[i].first - x) * (a[i].first - x) + (a[i].second - y) * (a[i].second - y);
		ans += dis[i];
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			dis2[i][j] = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
		}
	}
	pow2[0] = 1;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			//cout << dis2[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i = 1; i < 27; i ++)
	{
		pow2[i] = pow2[i - 1] * 2;
	}
	for(int i = 1; i < 50000000; i ++)
	{
		dp[i] = N;
	}
	for(int i = 1; i < pow2[n]; i ++)
	{
		int q;
		for(int j = 0; j <= 25; j ++)
		{
			if(get(i, j) == 1)
			{
				q = j;
				break;
			}
		}
		dp[i] = dp[i - pow2[q]] + dis[q];
		par[i] = i - pow2[q];
		for(int j = 0; j <= 25; j ++)
		{
			if(get(i, j) == 1 && q != j)
			{
				if(dp[i - pow2[q] - pow2[j]] + dis2[q][j] < dp[i])
				{
					dp[i] = dp[i - pow2[q] - pow2[j]] + dis2[q][j];
					par[i] = i - pow2[q] - pow2[j];
				}
				//cout << i << " " << q << " " << j << " " << dis2[q][j] << endl;
			}
		}
	}
	for(int i = 1; i <= 10; i ++)
	{
		//cout << i << " " << dp[i] << endl;
	}
	cout << dp[pow2[n] - 1] + ans << endl;
	cout << 0 << " ";
	int s = pow2[n] - 1;
	while(s != 0)
	{
		int t = s - par[s];
		//cout << s << " " << t << " " << par[s] << endl;
		for(int j = 0; j < 26; j ++)
		{
			if(get(t, j) == 1)
			{
				cout << j + 1 << " ";
			}
		}
		cout << 0 << " ";
		s = par[s];
	}
	return 0;
}