#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, a, b, ansa, ansb;
int ans[N];

int32_t main()
{
	IOS;
	cin>>n>>a>>b;

	int idx=2;
	ans[1]=1;
	int cursum=1;
	for(int i=1;i<=b;i++)
	{
		ans[idx]=cursum+1;
		cursum+=ans[idx++];
	}
	if(b==0 && a)
		ans[idx++]=1;
	for(int i=1;i<=a;i++)
	{
		ans[idx]=ans[idx-1]+1;
		idx++;
	}
	while(idx<=n)
		ans[idx++]=1;
	for(int i=2;i<=n;i++)
	{
		bool checksmall=0;
		bool allsmall=0;
		int sum=0;
		for(int j=1;j<i;j++)
		{
			checksmall|=(ans[j]<ans[i]);
			sum+=ans[j];
		}
		allsmall=(sum<ans[i]);
		ansb+=allsmall;
		ansa+=checksmall & (allsmall==0);
	}
	if(a!=ansa || b!=ansb)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}