/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#else
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


string horizon[1005];
string nobounds[1005];
char a[1005][1005];
void solve()
{
	int n,m,w;
	cin>>n>>m>>w;
	for(int i=1; i<n; i++)
		cin>>horizon[i]>>nobounds[i];
	cin>>horizon[n];
	int lolol=(n-1)*m+n*(m-1);
	if(w>1)
	{
		int assertions=n*(m-1);
		for(int j=1; j<=n; j++)
		{
			a[j][1]='1';
			for(int i=2; i<=m; i++)
				if(horizon[j][i-2]=='E')
					a[j][i]=a[j][i-1];
				else
					a[j][i]='1'+('2'-a[j][i-1]);
		}
		for(int i=2; i<=n; i++)
		{
			int match=0;
			for(int j=1; j<=m; j++)
				if(a[i-1][j]==a[i][j]) {
					if(nobounds[i-1][j-1]=='E')
						match++;
				}
				else if(nobounds[i-1][j-1]=='N')
					match++;
			if(2*match<m)
			{
				for(int j=1; j<=m; j++)
					a[i][j]='1'+('2'-a[i][j]);
				match=m-match;
			}
			assertions+=match;
		}
		if(4*assertions<3*lolol)
		{
			for(int j=1; j<=m; j++)
			{
				a[1][j]='1';
				for(int i=2; i<=n; i++)
					if(nobounds[i-1][j-1]=='E')
						a[i][j]=a[i-1][j];
					else
						a[i][j]='1'+('2'-a[i-1][j]);

			}
			for(int i=2; i<=m; i++)
			{
				int match=0;
				for(int j=1; j<=n; j++)
					if(a[j][i-1]==a[j][i]) {
						if(horizon[j][i-2]=='E')
							match++;
					}
					else if(horizon[j][i-2]=='N')
						match++;
				if(2*match<n)
				{
					for(int j=1; j<=n; j++)
						a[j][i]='1'+('2'-a[j][i]);
					match=m-match;
				}
			}
		}
		cout<<"YES"<<endl;
		for(int i=1; i<=n; i++,cout<<endl)
			for(int j=1; j<=m; j++)
				cout<<a[i][j]<<' ';
	}
	else
	{
		int lol=0;
		for(int i=1; i<=n; i++)
			for(int j=0; j<m-1; j++)
				if(horizon[i][j]=='E')
					lol++;
		for(int i=1; i<n; i++)
			for(int j=0; j<m; j++)
				if(nobounds[i][j]=='E')
					lol++;
		if(lol*4>=lolol*3)
		{
			cout<<"YES"<<endl;
			for(int i=1; i<=n; i++,cout<<endl)
				for(int j=1; j<=m; j++)
					cout<<"1 ";
		}
		else
			cout<<"NO"<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}