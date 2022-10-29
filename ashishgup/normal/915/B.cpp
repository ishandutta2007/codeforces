#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, pos, l, r;

int getleft()
{
	int ans=0;
	if(l!=1)
	{
		ans+=abs(pos-l);
		pos=l;
		ans++;
	}
	if(r!=n)
	{
		ans+=abs(r-pos);
		ans++;
	}
	return ans;
}

int getright()
{
	int ans=0;
	if(r!=n)
	{
		ans+=abs(pos-r);
		pos=r;
		ans++;
	}
	if(l!=1)
	{
		ans+=abs(pos-l);
		ans++;
	}
	return ans;
}

int32_t main() 
{
	IOS;
	cin>>n>>pos>>l>>r;
	int storepos=pos;
	int ans=getleft();
	pos=storepos;
	ans=min(ans, getright());
	cout<<ans;
}