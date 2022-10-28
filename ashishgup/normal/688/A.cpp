#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, d;

int32_t main()
{
    IOS;
    cin>>n>>d;
  	int cur=0, ans=0;
  	for(int i=1;i<=d;i++)
  	{
  		int check=0;
  		for(int j=1;j<=n;j++)
  		{
  			char ch;
  			cin>>ch;
  			check|=(ch=='0');
  		}
  		if(check)
  			cur++;
  		else
  			cur=0;
  		ans=max(ans, cur);
  	}  
  	cout<<ans;
	return 0;
}