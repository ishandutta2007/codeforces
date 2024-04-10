#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
    IOS;
   	int l, r, a;
   	cin>>l>>r>>a;
   	for(int i=1;i<=a;i++)
   	{
   		if(l<r)
   			l++;
   		else
   			r++;
   	}
   	cout<<min(l, r)*2;
    return 0;
}