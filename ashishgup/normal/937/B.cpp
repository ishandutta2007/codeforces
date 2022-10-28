#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int p, y;

int mindiv(int k)
{
	int cur=p+1;
	for(int i=2;i*i<=k;i++)
	{
		if(k%i)
			continue;
		cur=min(cur, i);
		cur=min(cur, k/i);
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin>>p>>y;
	for(int i=y;i>p;i--)
	{
		if(mindiv(i)<=p)
			continue;
		cout<<i;
		return 0;
	}
	cout<<"-1";
	return 0;
}