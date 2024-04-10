#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5001;
const int MOD=1e9+7;

int n;
string s;
int32_t lcp[N][N], dp[N][N], sum[N][N];

void preprocess()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(s[i]==s[j])
				lcp[i][j]=lcp[i+1][j+1] + 1;
			else
				lcp[i][j]=0;
		}
	}
}

bool check_less(int idx1, int idx2, int len)
{
	int common=lcp[idx1][idx2];
	if(common>=len)
		return 0;
	return s[idx1+common]<s[idx2+common];
}

int32_t main()
{
	IOS;
	cin>>n>>s;
	s='*'+s;
	preprocess();
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
		for(int len=1;len<=n;len++)
		{
			sum[i][len]+=sum[i][len-1] + dp[i][len];
			sum[i][len]%=MOD;
		}
		if(s[i+1]!='0')
		{
			for(int len=1;i+len<=n;len++)
			{
				dp[i+len][len]+=sum[i][len-1];
				dp[i+len][len]%=MOD;
				if(len<=i && check_less(i-len+1, i+1, len))
				{
					dp[i+len][len]+=dp[i][len];
					dp[i+len][len]%=MOD;
				}
			}
		}
	}
	cout<<sum[n][n];
	return 0;
}