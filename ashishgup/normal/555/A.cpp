#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, ans=-1, idx=1, cnt=0;
bool started=0, ended=0;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		int sz, prev;
		cin>>sz;
		ans+=(2*(sz-1));
		for(int j=1;j<=sz;j++)
		{
			int x;
			cin>>x;
			if(x==idx && !ended)
			{
				started=1;
				idx++;
				cnt++;
			}
			else
			{
				if(started && !ended)
				{
					ended=1;
					ans-=2*(cnt-1);
				}
			}
		}
		if(started && !ended)
		{
			ended=1;
			ans-=(2*(cnt-1));
		}
		ans++;
	}
	cout<<ans;
	return 0;
}