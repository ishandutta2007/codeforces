#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

string A , s[maxn];

int cost[maxn] , dp[maxn][maxn] , last[maxn];

pair<int , int> srt[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A;
	int n , m = A.size();
	cin >> n;

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			dp[i][j] = -2e9;

	for(auto &ch : A)
		ch -= '0';

	int N = m;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		N = max(N , (int)s[i].size());
	}

	N += 5;

	for(int i = 0; i < 10; i++)
		cin >> cost[i];

	reverse(A.begin() , A.end());
	while((int)A.size() < N)
		A += (char)(0);

	for(int i = 0; i < n; i++)
	{
		last[i] = s[i].size();
		reverse(s[i].begin() , s[i].end());
		while((int)s[i].size() < N)
			s[i] += "0";

		srt[i] = {s[i][0] , i};
	}

	sort(srt , srt + n);
	reverse(srt , srt + n);

	dp[0][0] = 0;
	for(int i = 0; i < N; i++)
	{
		int l , r;

		if(A[i] == '?' - '0')
			l = 0 , r = 9;
		else
			l = r = A[i];

		if(i == m - 1 && A[i] == '?' - '0')
			l = 1;

		for(int k = l; k <= r; k++)
		{
			int pt = 0 , add = 0;

			for(int j = 0; j < n; j++)
			{
				int ind = srt[j].second;

				int nxt = s[ind][i] - '0' + k;
				if(nxt >= 10)
					pt++;

				if(max(last[ind] , m) > i || nxt > 0)
					add += cost[nxt % 10];
			}

			for(int j = 0; j <= n; j++)
			{
				dp[i + 1][pt] = max(dp[i + 1][pt] , dp[i][j] + add);

				if(j == n)
					continue;

				int ind = srt[j].second;
				int nxt = s[ind][i] - '0' + k;

				if(nxt == 9)
					pt++;

				if(max(last[ind] , m) > i || nxt > 0)
					add -= cost[nxt % 10];

				add += cost[(nxt + 1) % 10];
			}
		}

		reverse(srt , srt + n);

		for(int j = 0; j < n; j++)
		{
			int ind = srt[j].second;
			srt[j].first = n * s[ind][i] + j;
		}

		sort(srt , srt + n);
		reverse(srt , srt + n);
	}

	cout << dp[N][0] << endl;
}