#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, curans, ans;
int a[N];
vector<int> on, off;

void insertbefore()
{
	int offtime=0;
	for(auto it:off)
		offtime+=it;
	int ontime=0;
	for(int i=0;i<on.size();i++)
	{
		if(on[i]>1)
		{
			int cur=ontime + on[i]-1 + offtime;
			ans=max(ans, cur);
		}
		ontime+=on[i];
		if(i<off.size())
			offtime-=off[i];
	}
}

void insertafter()
{
	int offtime=0;
	for(auto it:off)
		offtime+=it;
	int ontime=0;
	for(int i=0;i<off.size();i++)
	{
		ontime+=on[i];
		offtime-=off[i];
		if(off[i]>1)
		{
			int cur=ontime + off[i]-1 + offtime;
			ans=max(ans, cur);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	curans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2)
		{
			curans+=a[i]-a[i-1];
			on.push_back(a[i]-a[i-1]);
		}
		else
			off.push_back(a[i]-a[i-1]);
	}
	if((n+1)%2)
	{
		curans+=m-a[n];
		on.push_back(m-a[n]);
	}
	else
		off.push_back(m-a[n]);
	ans=curans;
	insertbefore();
	insertafter();
	cout<<ans;
	return 0;
}