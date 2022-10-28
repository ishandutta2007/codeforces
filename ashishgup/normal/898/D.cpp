#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	int counter=0, ans=0;	
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		while(q.size()>0&&(a[i]-q.front())>=m)
		{
			counter--;
			q.pop();
		}
		counter++;
		if(counter>=k)
		{
			counter--;
			ans++;
		}
		else
		{
			q.push(a[i]);
		}
	}
	cout<<ans;
   	return 0;
}