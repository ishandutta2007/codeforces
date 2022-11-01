#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	s='?'+s;
	for(int i=1;i<=n;i++) s[i]=(((s[i]-'0')%3)+'0');
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(s[i]=='0') dp[i]=max(dp[i],dp[i-1]+1);
        if(i>=3&&s[i-2]=='1'&&s[i-1]=='1'&&s[i]=='1') dp[i]=max(dp[i],dp[i-3]+1);
        if(i>=2&&s[i-1]=='1'&&s[i]=='2') dp[i]=max(dp[i],dp[i-2]+1);
        if(i>=2&&s[i-1]=='2'&&s[i]=='1') dp[i]=max(dp[i],dp[i-2]+1);
        if(i>=3&&s[i-2]=='2'&&s[i-1]=='2'&&s[i]=='2') dp[i]=max(dp[i],dp[i-3]+1);
    }
    cout << dp[n] << endl;
	return 0;
}