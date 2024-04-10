/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[101][101];
int negrow[101],negcol[101];
signed main()
{
	IO;
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];
	for(int i=0; i<n*m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int su=0;
			for(int k=1; k<=m; k++)
				su+=a[j][k];
			if(su<0)
			{
				negrow[j]++;
				for(int k=1; k<=m; k++)
					a[j][k]*=-1;
			}
		}
		for(int j=1; j<=m; j++)
		{
			int su=0;
			for(int k=1; k<=n; k++)
				su+=a[k][j];
			if(su<0)
			{
				negcol[j]++;
				for(int k=1; k<=n; k++)
					a[k][j]*=-1;
			}
		}
	}
	int surow=0,sucol=0;
	for(int i=1; i<=n; i++)
		surow+=negrow[i]&1;
	for(int i=1; i<=m; i++)
		sucol+=negcol[i]&1;
	cout<<surow<<" ";
	for(int i=1; i<=n; i++)
		if(negrow[i]&1)
			cout<<i<<" ";
	cout<<endl;
	cout<<sucol<<endl;
	for(int i=1; i<=m; i++)
		if(negcol[i]&1)
			cout<<i<<" ";

}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}