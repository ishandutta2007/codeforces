#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, ans=1;
int a[N];
queue<int> q;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(i);
	}
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		ans=cur;
		a[cur]-=m;
		if(a[cur]>0)
			q.push(cur);
	}	
	cout<<ans;
	return 0;
}