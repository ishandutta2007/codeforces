#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int dp[100005];
int cal(int x)
{
	if(x<=200) return dp[x];
	return dp[x%68+136];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=2;i<=1000;i++)
	{
		vector<int> v;
		for(int j=0;j<=i-2;j++)
		{
			v.push_back(dp[j]^dp[i-j-2]);
		}
		sort(v.begin(),v.end());
		if(v[0]!=0) dp[i]=0;
		else
		{
			int flag=0;
			int X=i;
			for(int i=1;i<v.size();i++)
			{
				if(v[i]==v[i-1]) continue;
				if(v[i]!=v[i-1]+1)
				{
					dp[X]=v[i-1]+1;
					flag=1;
					break;
				}
			}
			if(!flag) dp[X]=v.back()+1;
		}
	}
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		string s;
		cin >> n >> s;
		int cnt1=0,cnt2=0;
		for(auto t:s)
		{
			if(t=='R') ++cnt1;
			else ++cnt2;
		}
		if(cnt1!=cnt2)
		{
			if(cnt1>cnt2) cout << "Alice\n";
			else cout << "Bob\n";
			continue;
		}
		int len=1;
		s=' '+s;
		int nw=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[i-1])
			{
				nw^=cal(len);
				len=0;
			}
			++len;
		}
		nw^=cal(len);
		if(nw) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}