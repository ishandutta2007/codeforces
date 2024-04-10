#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int check(int a, int b, int c)
{
	int check1=((a+b)>c);
	int check2=((b+c)>a);
	int check3=((a+c)>b);
	int check4=check1&check2&check3;
	return check4;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int ans=0;
    for(int a=1;a<=n;a++)
    {
    	for(int b=a;b<=n;b++)
    	{
    		int c=a^b;
    		if(c>n)
    			continue;
    		if(c>=b&&check(a, b, c))
    		{
    			ans++;
    		}
    	}
    }
    cout<<ans;
    return 0;
}