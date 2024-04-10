#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3072;
const int MOD = 998244353;

int N;
string S, T;
int dp[MAXN][MAXN]; //[i, j] inclusive
int main()
{
	cin >> S >> T;
	int M = T.size();
	while(S.size() != T.size())
	{
		T += '?';
	}
	N = S.size();
	for(int i=0; i<N; ++i)
	{
		if(T[i] == S[0] || T[i] == '?')
			dp[i][i] = 2;
		else
			dp[i][i] = 0;
	}
	for(int L=1; L<N; ++L)
		for(int i=0; i<N-L; ++i)
		{
			int j = i+L;
			dp[i][j] = 0;
			if(T[i] == '?' || T[i] == S[L])
				dp[i][j] += dp[i+1][j];
			if(T[j] == '?' || T[j] == S[L])
				dp[i][j] += dp[i][j-1];
			if(dp[i][j] >= MOD) dp[i][j] -= MOD;
		}
	int ans = 0;
	for(int i=M-1; i<=N-1; ++i)
	{
		ans += dp[0][i];
		if(ans >= MOD) ans -= MOD;
	}
	printf("%d\n", ans);
}