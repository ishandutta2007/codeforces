#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b>0)
	{
		if(b%2)
		{
			ans*=a;
			ans%=m;
		}
		a*=a;
		a%=m;
		b/=2;
	}
	return ans;
}

int32_t main()
{
    IOS;
    int n, m;
    cin>>n>>m;
    int ans=pow(3LL, n, m);
    ans-=1;
    ans+=m;
    ans%=m;
    cout<<ans;
    return 0;
}