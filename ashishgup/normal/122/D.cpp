#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
char a[N];
int vis[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
		if(a[i]=='4' && a[i+1]=='7')
			s.insert(i);
	while(k-- && s.size())
	{
		int idx=*s.begin();
		s.erase(idx);
		if(idx%2)
		{
			a[idx+1]='4';
			if(idx+2<=n && a[idx+2]=='7')
				s.insert(idx+1);
		}
		else
		{
			a[idx]='7';
			if(idx-1>=1 && a[idx-1]=='4')
				s.insert(idx-1);
		}
		if(vis[idx])
			k%=2;
		vis[idx]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}