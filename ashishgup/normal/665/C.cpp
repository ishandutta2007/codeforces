#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;
int n;
int cache[N][26];
string s, output="";

int dp(int i, char prev)
{
	if(i==n)
		return 0;
	if(cache[i][prev-'a']!=-1)
		return cache[i][prev-'a'];
	int &ans=cache[i][prev-'a'];
	ans=INT_MAX;
	for(char ch='a';ch<='z';ch++)
	{
		if(ch==prev)
			continue;
		int cur=(ch!=s[i]);
		ans=min(ans, cur+dp(i+1, ch));
	}
	return ans;
}

void path(int i, char prev)
{
	output+=prev;
	if(i==n)
		return;
	for(char ch='a';ch<='z';ch++)
	{
		if(ch==prev)
			continue;
		int cur=(ch!=s[i]);
		if(dp(i, prev)==(cur+dp(i+1, ch)))
		{
			path(i+1, ch);
			return;
		}
	}
}

int main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s;
	n=s.size();
	int ans=dp(1, s[0]);
	path(1, s[0]);
	cout<<output;
	return 0;
}