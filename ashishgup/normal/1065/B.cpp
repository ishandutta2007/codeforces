#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	int minisolated=max(0LL, n-2*m);
	for(int i=0;i<=n;i++)
	{
		int edges=i*(i-1)/2;
		if(edges>=m)
		{
			cout<<minisolated<<" "<<n-i<<endl;
			return 0;
		}
	}
	return 0;
}