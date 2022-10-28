#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int m[26][5005][26];

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int n=s.size();
	s+=s;
	long double ans=0;
	for(int i=0;i<s.size()/2;i++)
	{
		char ch=s[i];
		int ctr=1;
		for(int j=i+1;ctr<=n-1;j++)
		{
			m[ch-'a'][ctr][s[j]-'a']++;
			ctr++;
		}
	}
	for(char ch='a';ch<='z';ch++)
	{
		int max1=0;
		for(int i=1;i<=n-1;i++)
		{
			int cur=0;
			for(int j=0;j<=25;j++)
			{
				cur+=(m[ch-'a'][i][j]==1);
			}
			max1=max(max1, cur);
		}
		ans+=max1;
	}
	ans/=n;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}