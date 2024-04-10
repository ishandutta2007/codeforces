#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, i, j, a ,b;

int calc(int x1, int y1, int x2, int y2)
{
	int xdiff=abs(x1-x2);
	int ydiff=abs(y1-y2);
	if(xdiff%a)
		return 1e15;
	if(ydiff%b)
		return 1e15;
	int xmoves=xdiff/a;
	int ymoves=ydiff/b;
	if(xmoves%2 != ymoves%2)
		return 1e15;
	if(xmoves!=ymoves)
	{
		if(ymoves<xmoves)
		{
			if(j+b>m && j-b<1)
				return 1e15;
		}
		if(xmoves<ymoves)
		{
			if(i+a>n && i-a<1)
				return 1e15;
		}
	}
	return max(xmoves, ymoves);
}

int32_t main()
{
	IOS;
	cin>>n>>m>>i>>j>>a>>b;
	int ans=1e15;
	ans=min(ans, calc(i, j, 1, 1));
	ans=min(ans, calc(i, j, 1, m));
	ans=min(ans, calc(i, j, n, 1));
	ans=min(ans, calc(i, j, n, m));
	if(ans==1e15)
	{
		cout<<"Poor Inna and pony!";
		return 0;
	}
	cout<<ans;
	return 0;
}