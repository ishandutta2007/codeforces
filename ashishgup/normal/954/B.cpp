#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, ans;
string s;

void work()
{
	for(int i=1;i<n;i++)
	{
		int len=i;
		if(i+len-1>=n)
			break;
		int curlen=0;
		int check=1;
		for(int j=0, k=i;j<i;j++, k++)
		{
			if(s[j]!=s[k])
			{
				check=0;
				break;
			}
		}
		if(check)
		{
			ans=min(ans, n-len+1);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	cin>>s;
	ans=n;
	work();
	cout<<ans;
	return 0;
}