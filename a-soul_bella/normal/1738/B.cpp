#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int k,n;
		cin >> n >> k;
		for(int i=1;i<=k;i++)
			cin >> s[i];
		if(k==1)
		{
			cout << "Yes\n";
			continue; 
		}
		int flag=1;
		for(int i=3;i<=k;i++)
		{
			if(s[i]-s[i-1]<s[i-1]-s[i-2])
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			cout << "No\n";
			continue;
		}
		int nw=s[2]-s[1];
		if(s[1]-nw*(n-k+1)>0)
		{
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
	return 0;
}