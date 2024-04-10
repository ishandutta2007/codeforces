#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int p, ans=0;

int32_t main()
{
	IOS;
	cin>>p;
	for(int i=1;i<p;i++)
	{
		int x=i;
		bool check=1;
		for(int j=1;j<=p-2;j++, x=(x*i)%p)
			check&=(x!=1);
		ans+=check;
	}	
	cout<<ans;
	return 0;
}