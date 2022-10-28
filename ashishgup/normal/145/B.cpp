#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int a1, a2, a3, a4;
deque<char> ans;

int32_t main()
{
    IOS;
    cin>>a1>>a2>>a3>>a4;
    if(a3>min(a1,a2) || a4>min(a1, a2) || abs(a3-a4)>1)
    {
    	cout<<"-1";
    	return 0;
    }
    for(int i=1;i<=a3;i++)
    {
    	ans.push_back('4');
    	ans.push_back('7');
    }
    a1-=a3;
    a2-=a3;
    a4-=max(0, a3-1);
    a3=0;
    if(a1 && a4)
    {
    	ans.push_back('4');
    	a1--;
    	a4--;
    }
    if(a2 && a4)
    {
    	ans.push_front('7');
    	a2--;
    	a4--;
    }
    if(a3 || a4)
    {
    	cout<<"-1";
    	return 0;
    }
    int first4=-1, last7=0;
    for(int i=0;i<ans.size();i++)
    {
    	if((ans[i]=='4')&&first4==-1)
    		first4=i;
    	if(ans[i]=='7')
    		last7=i;
    }
    for(int i=0;i<ans.size();i++)
    {
    	if(i==first4)
    	{
    		while(a1>0)
    		{
    			cout<<"4";
    			a1--;
    		}
    	}
    	if(i==last7)
    	{
    		while(a2>0)
    		{
    			cout<<"7";
    			a2--;
    		}
    	}
    	cout<<ans[i];
    }
    return 0;
}