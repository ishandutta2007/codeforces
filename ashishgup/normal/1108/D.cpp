#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
char a[N];
int b[N], cache[N][4];
map<char, int> m;
map<int, char> rm;

int dp(int idx, int prev)
{
	if(idx==n+1)
		return 0;
	int &ans=cache[idx][prev];
	if(ans!=-1)
		return ans;
	ans=1e9;
	for(int i=0;i<=2;i++)
	{
		if(i==prev)
			continue;
		ans=min(ans, (i!=b[idx]) + dp(idx+1, i));
	}
	return ans;
}

void path(int idx, int prev)
{
	if(idx==n+1)
		return;
	int &ans=cache[idx][prev];
	for(int i=0;i<=2;i++)
	{
		if(i==prev)
			continue;
		if(ans==((i!=b[idx]) + dp(idx+1, i)))
		{
			cout<<rm[i];
			return path(idx+1, i);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	m['B']=0;
	m['G']=1;
	m['R']=2;
	rm[0]='B';
	rm[1]='G';
	rm[2]='R';
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=m[a[i]];
	}
	int ans=dp(1, 3);
	cout<<ans<<endl;
	path(1, 3);
	return 0;
}