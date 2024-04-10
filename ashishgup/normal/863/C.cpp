#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5;

int k, a, b, n=3, alice=0, bob=0;
int nxtA[N][N], nxtB[N][N];
set<pair<int, int> > win;

int get(int x, int y)
{
	if(win.find({x, y})!=win.end())
		return 1;
	return 0;
}

void work(int period)
{
	if(k<period)
	{
		for(int cur=0;cur<k;cur++)
		{
			alice+=get(a, b);
			bob+=get(b, a);
			int na=nxtA[a][b];
			int nb=nxtB[a][b];
			a=na;
			b=nb;
		}
	}
	else
	{
		int cur=0;
		for(;cur<(k%period)+period;cur++)
		{
			alice+=get(a, b);
			bob+=get(b, a);
			int na=nxtA[a][b];
			int nb=nxtB[a][b];
			a=na;
			b=nb;
		}
		int pA=0, pB=0;
		for(int i=0;i<period;i++)
		{
			pA+=get(a, b);
			pB+=get(b, a);
			int na=nxtA[a][b];
			int nb=nxtB[a][b];
			a=na;
			b=nb;
		}
		alice+=pA*((k-cur)/period);
		bob+=pB*((k-cur)/period);
	}
	cout<<alice<<" "<<bob;
}

int32_t main()
{
	IOS;
	win.insert({1, 3});
	win.insert({3, 2});
	win.insert({2, 1});
	cin>>k>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>nxtA[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>nxtB[i][j];
	int period=8*9*5*7;
	work(period);
	return 0;
}