#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, q, start1=0, start2=1;
int ans[N];
int offset[2]={+1, -1};

int32_t main()
{
	IOS;	
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int x;
			cin>>x;
			start1+=(x+n);
			start1%=n;
			start2+=(x+n);
			start2%=n;
		}
		else
		{
			start1+=offset[start1%2];
			start2+=offset[start2%2];
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		ans[start1]=i;
		start1+=2;
		start1%=n;
	}
	for(int i=2;i<=n;i+=2)
	{
		ans[start2]=i;
		start2+=2;
		start2%=n;
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}