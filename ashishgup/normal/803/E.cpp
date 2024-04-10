#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, k;
string s;
int cache[N][2*N];

int dp(int idx, int diff)
{
	if(idx==n)
		return (abs(diff)==k);
	if(abs(diff)==k)
		return 0;
	int &ans=cache[idx][diff+N];
	if(ans!=-1)
		return ans;
	ans=0;
	if(s[idx]=='L')
		ans=dp(idx+1, diff-1);
	else if(s[idx]=='W')
		ans=dp(idx+1, diff+1);
	else if(s[idx]=='D')
		ans=dp(idx+1, diff);
	else
		ans=dp(idx+1, diff-1) | dp(idx+1, diff) | dp(idx+1, diff+1);
	return ans;
}

void path(int idx, int diff)
{
	if(idx==n)
		return;
	if(s[idx]=='L')
	{
		cout<<'L';
		return path(idx+1, diff-1);
	}
	else if(s[idx]=='W')
	{
		cout<<'W';
		return path(idx+1, diff+1);
	}
	else if(s[idx]=='D')
	{
		cout<<'D';
		return path(idx+1, diff);
	}
	else
	{
		if(dp(idx+1, diff-1))
		{
			cout<<'L';
			return path(idx+1, diff-1);
		}
		else if(dp(idx+1, diff))
		{
			cout<<'D';
			return path(idx+1, diff);
		}
		else
		{
			cout<<'W';
			return path(idx+1, diff+1);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k>>s;
	if(dp(0, 0))
		path(0, 0);
	else
		cout<<"NO";
	return 0;
}