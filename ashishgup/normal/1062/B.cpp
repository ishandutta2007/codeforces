#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, ans=1, maxf=0;
	cin>>n;
	map<int, int> m;
	for(int i=2;i<=n;i++)
	{
		if(n%i)
			continue;
		int cur=0;
		while(n%i==0)
		{	
			cur++;
			n/=i;
		}
		ans*=i;
		m[i]=cur;
		maxf=max(maxf, cur);
	}
	int check=0;
	for(auto &it:m)
		check|=(it.second!=maxf);
	int bits=__builtin_popcountll(maxf);
	check|=(bits>1);
	if(bits>1)
		maxf*=2;
	int ans2=check;
	while(maxf>1)
	{
		ans2++;
		maxf/=2;
	}
	cout<<ans<<" "<<ans2;
	return 0;
}