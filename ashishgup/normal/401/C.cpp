#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    string ans1="";
    int check1=n>m;
    int a=n, b=m;
    while(a>0 && b>0)
    {
    	if(check1)
    		ans1+="01";
    	else
    		ans1+="10";
    	a--, b--;
    }
    int max0=1;
    int max1=2;
    int sz1=ans1.size();
    string ans2="";
    for(int i=0;i<sz1;i++)
    {
    	ans2+=ans1[i];
    	if(ans1[i]=='0')
    	{
    		int cur=max0-1;
    		int left=a;
    		for(int j=1;j<=min(left, cur);j++)
    		{
    			ans2+='0';
    			a--;
    		}
    	}
    	else
    	{
    		int cur=max1-1;
    		int left=b;
    		for(int j=1;j<=min(left, cur);j++)
    		{
    			ans2+='1';
    			b--;
    		}
    	}
    }
    if(a>1||b>2)
    {
    	cout<<"-1";
    	return 0;
    }
    else
    {
    	while(a>0)
    	{
    		ans2+="0";
    		a--;
    	}
    	while(b>0)
    	{
    		ans2+="1";
    		b--;
    	}
	}
	cout<<ans2;
    return 0;
}