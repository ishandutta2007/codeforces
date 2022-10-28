#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int cnt[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline int get(int k)
{
	int ans=0;
	while(k>0)
	{
		ans+=cnt[k%10];
		k/=10;
	}
	return ans;
}

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	int ans=0;
	for(int i=a;i<=b;i++)
		ans+=get(i);
	cout<<ans;
	return 0;
}