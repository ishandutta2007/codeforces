#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, dx, dy;
int ans[N], moves[N];

int32_t main()
{
	cin>>n>>m>>dx>>dy;
	ans[1]=0;
	int cury=1;
	cury+=dy;
	cury%=n;
	for(int i=n-1;i>=1;i--)
	{
		moves[cury]=i;
		cury+=dy;
		cury%=n;
	}
	int ansx, ansy, maxans=0;
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		if(ans[(x+moves[y]*dx)%n]+1>maxans)
		{
			maxans=ans[(x+moves[y]*dx)%n]+1;
			ansx=x;
			ansy=y;
		}
		ans[(x+moves[y]*dx)%n]++;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}