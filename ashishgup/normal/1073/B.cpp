#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, idx=1;
int a[N], b[N], ans[N];
set<int> taken;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(taken.find(b[i])!=taken.end())
		{
			cout<<0<<" ";
			continue;
		}
		int cnt=0;
		while(true)
		{
			cnt++;
			taken.insert(a[idx++]);
			if(taken.find(b[i])!=taken.end())
			{
				cout<<cnt<<" ";
				break;
			}
		}
	}
	return 0;
}