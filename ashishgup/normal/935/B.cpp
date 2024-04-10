#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int getside(int x, int y)
{
	if(x>y)
		return 1;
	else if(y>x)
		return 2;
	else
		return 0;
}   

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0, y=0, cur=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')
			y++;
		else
			x++;
		int side=getside(x, y);
		if(side!=0 && side!=cur)
		{
			if(i!=0)
				ans++;
			cur=side;
		}
	}
	cout<<ans;
	return 0;
}