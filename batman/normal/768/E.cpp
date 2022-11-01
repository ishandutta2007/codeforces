#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)

ll n,ans,g[61]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x;
		scanf("%d",&x);
		ans^=g[x];
	}
	cout<<((ans)?"NO":"YES");
	return 0;
}