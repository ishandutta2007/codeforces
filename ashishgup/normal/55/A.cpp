#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;

int n;
int vis[N];

int32_t main()
{
	IOS;
	cin>>n;
	int cur=0, tot=0;
	for(int i=1;i<=n+1;i++)
	{
		tot+=(vis[cur]==0);
		vis[cur]=1;
		cur+=(i-1);
		cur%=n;
	}
	if(tot==n)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}