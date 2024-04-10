#include <bits/stdc++.h>
using namespace std;

const int N = 1000002;
char s[N];
int ok[N];
int dp[N];
int n;
vector<int> p;

bool check(int x)
{
	int k = p.size();
	dp[0] = ok[0];
	for(int i = 1; i <= k; i++)
	{
		int t = p[i-1];
		if(t - x - 1 > dp[i-1])
			return false;
		if(dp[i-1] >= t) dp[i] = ok[min(n, t+x)];
		else
		{
			dp[i] = ok[t];
			if(i > 1 && t - x - 1 <= dp[i-2])
				dp[i] = max(dp[i], ok[min(n, p[i-2]+x)]);
		}
	}
	return dp[k] == n;
}

int main()
{
	scanf("%d %s", &n, s + 1);
	for(int i = 1; i <= n; i++)
		if(s[i] == 'P') p.push_back(i);
	if(p.size() == 1)
	{
		int a = 0, b = 0, f = 0, l;
		for(int i = 1; i <= n; i++)
			if(s[i] == '*')
			{
				if(i < p[0]) a++;
				else b++;
				if(f == 0) f = i;
				l = i;
			}
		int da = p[0] - f, db = l - p[0];
		auto ans = max(make_pair(a, -da), make_pair(b, -db));
		printf("%d %d\n", ans.first, -ans.second);
	}
	else
	{
		int ast = 0;
		ok[n] = n;
		for(int i = n; i > 0; i--)
			if(s[i] == '*')
			{
				ast++;
				ok[i-1] = i-1;
			}
			else ok[i-1] = ok[i];
		int a = 1, b = n, c;
		while(a < b)
		{
			c = (a + b) / 2;
			if(check(c)) b = c;
			else a = c + 1;
		}
		printf("%d %d\n", ast, a);
	}
}