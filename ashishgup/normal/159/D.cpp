#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

string s;
int pref[N];
bool vis[N][N], cache[N][N];

int check(int i, int j)
{
	if(i>=j)
		return 1;
	if(vis[i][j])
		return cache[i][j];
	bool &ans=cache[i][j];
	vis[i][j]=1;
	if(s[i]==s[j])
		ans|=check(i+1, j-1);
	else
		ans=0;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(check(i, j))
				pref[j]++;
		}
	}
	for(int i=1;i<n;i++)
		pref[i]+=pref[i-1];
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(check(i, j))
				ans+=pref[i-1];
		}
	}
	cout<<ans;
	return 0;
}