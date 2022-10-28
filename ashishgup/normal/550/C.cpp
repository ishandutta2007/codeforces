#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
string s, output="";
int cache[105][2][10];

int dp(int i, bool taken, int rem)
{
	if(cache[i][taken][rem]!=-1)
		return cache[i][taken][rem];
	int ans=0;
	if(taken && !(rem))
		ans=1;
	for(int j=i+1;j<n;j++)
		ans|=dp(j, 1, (rem*10 + s[j]-'0')%8);
	cache[i][taken][rem]=ans;
	return ans;
}

void findpath(int i, bool taken, int rem)
{
	if(i!=0)
		output+=s[i];
	if(taken && !(rem))
		return;
	for(int j=i+1;j<n;j++)
	{
		if(dp(j, 1, (rem*10 + s[j]-'0')%8))
		{
			findpath(j, 1, (rem*10 + s[j]-'0')%8);
			return;
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s;
	s="0"+s;
	n=s.size();
	int check=dp(0, 0, 0);
	if(!check)
	{
		cout<<"NO";
		return 0;
	}
	findpath(0, 0, 0);
	cout<<"YES"<<endl;
	cout<<output;
	return 0;
}