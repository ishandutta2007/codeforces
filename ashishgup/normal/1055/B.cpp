#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, l, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l)
			continue;
		int j=i;
		while(j+1<=n && a[j+1]>l)
			j++;
		ans++;
		i=j;
	}
	while(m--)
	{
		int type;
		cin>>type;
		if(type==0)
			cout<<ans<<endl;
		else
		{
			int idx, val;
			cin>>idx>>val;
			if(a[idx]>l)
				continue;
			a[idx]+=val;
			if(a[idx]>l)
			{
				if(a[idx-1]>l && a[idx+1]>l)
					ans--;
				else if(a[idx-1]<=l && a[idx+1]<=l)
					ans++;
			}
		}
	}	
	return 0;
}