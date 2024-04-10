#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		int ans=(r-l+1)/2;
		if(l%2==0)
			ans*=-1;
		if((r-l+1)%2)
		{
			if(r%2)
				ans-=r;
			else
				ans+=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}