#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 20;
 
int n, k ;
double p[N], answer[N];
double dp[1 << N];
 
void work()
{	
	dp[0] = 1;
	for(int mask = 1; mask < (1 << n); mask++)
	{
		double &ans = dp[mask];
		double den = 0, num = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(mask >> i & 1)
			{
				cnt++;
				den += p[i];
				num += p[i] * dp[mask ^ (1 << i)];
			}
		}
		ans = num / (1 - den);
		if(cnt == k)
			for(int i = 0; i < n; i++)
				if(mask >> i & 1)
				answer[i] += num;
	}
}
 
int32_t main()
{
	IOS;
	cin >> n >> k;
	int ct = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		ct += (p[i] > 0);
	}
	k = min(k, ct);
	work();
	cout << fixed << setprecision(12);
	for(int i = 0; i < n; i++)
		cout << answer[i] << " ";
	return 0;
}