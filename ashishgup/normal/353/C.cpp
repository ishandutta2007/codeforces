#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], cache[N][2];
string s;

int dp(int i, int flip)
{
	if(i>=n)
		return 0;
	if(cache[i][flip]!=-1)
		return cache[i][flip];
	int &ans=cache[i][flip];
	if(flip)
	{
		ans = a[i] + dp(i+1, flip);
	}
	else
	{
		if(s[i]=='0')
		{
			ans=dp(i+1, flip);
		}
		else
		{
			ans=max(a[i] + dp(i+1, flip), dp(i+1, 1));
		}
	}
	return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    cin>>s;
    reverse(s.begin(), s.end());
    reverse(a, a+n);
    int ans=dp(0, 0);
    cout<<ans;
    return 0;
}