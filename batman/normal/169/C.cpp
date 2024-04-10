#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (5555)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s,t;
ll dp[N][N],ans;

int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<t.size();j++)
		{
			if(j)dp[i][j]+=dp[i][j-1];
			if(s[i]==t[j])dp[i][j]+=((i && j)?dp[i-1][j-1]:0)+1;
			dp[i][j]%=MOD;
		}
		ans+=dp[i][t.size()-1];
		ans%=MOD;
	}
	cout<<ans;
    return 0;
}