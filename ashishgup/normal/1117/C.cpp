#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int x1, y1, x2, y2, xdiff, ydiff;
char a[N];
int curx[N], cury[N];

bool check(int k)
{
	int x=curx[n] * (k/n);
	int y=cury[n] * (k/n);
 	x+=curx[k%n];
 	y+=cury[k%n];
 	return abs(xdiff-x) + abs(ydiff-y) <= k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	if(!check(lo))
		lo=-1;
	return lo;
}

int32_t main()
{
	IOS;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	xdiff=x2 - x1;
	ydiff=y2 - y1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		curx[i]=curx[i-1];
		cury[i]=cury[i-1];
		if(a[i]=='U')
			cury[i]++;
		else if(a[i]=='D')
			cury[i]--;
		else if(a[i]=='R')
			curx[i]++;
		else
			curx[i]--;
	}
	int ans=binsearch(0, 2e14);
	cout<<ans;
	return 0;
}