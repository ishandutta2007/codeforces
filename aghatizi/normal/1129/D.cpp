#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 320;
const int qs = maxn / sq+3;
const int mod = 998244353;

int l[maxn] , last[maxn] , a[maxn] , x[maxn] , ptr[qs][maxn * 2] , zero[qs] , dp[maxn];
int n , k , sum[qs];
int *t[qs];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void handle(int r , int val)
{
	mkay(t[r / sq][x[r]] -= dp[r]);
	if(x[r] + zero[r / sq] <= k)
		mkay(sum[r / sq] -= dp[r]);

	x[r] += val;
	mkay(t[r / sq][x[r]] += dp[r]);
	if(x[r] + zero[r / sq] <= k)
		mkay(sum[r / sq] += dp[r]);
}

void Add(int l , int r , int val)
{
	while(l < r && l % sq)
	{
		handle(l , val);
		l++;
	}
	while(l < r && r % sq)
	{
		r--;
		handle(r , val);
	}
	for(int i = l / sq; i < r / sq; i++)
	{
		if(val == 1)
			mkay(sum[i] -= t[i][k - zero[i]]);
		else
			mkay(sum[i] += t[i][k + 1 - zero[i]]);

		zero[i] += val;
	}
}
int get(int r)
{
	int ans = 0;
	for(int i = 0; i <= r / sq; i++)
		mkay(ans += sum[i]);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < qs; i++)
		t[i] = &ptr[i][maxn];

	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	dp[0] = 1;
	mkay(t[0][0] += 1);
	mkay(sum[0] += 1);
	for(int i = 1; i <= n; i++)
	{
		Add(l[a[i]] , last[a[i]] , -1);
		Add(last[a[i]] , i , 1);
		dp[i] = get(i);
		mkay(t[i / sq][-zero[i / sq]] += dp[i]);
		mkay(sum[i / sq] += dp[i]);
		l[a[i]] = last[a[i]];
		last[a[i]] = i;
	}
	cout << dp[n] << endl;
}