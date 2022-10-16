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

int a[11][100001];
int ra[11][100001];
int b[100001];
signed main()
{
	IO;
	int n,m;
	cin>>n>>m;
	for(int j=1; j<=m; j++)
		for(int i=1; i<=n; i++)
			cin>>a[j][i];
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			ra[i][a[i][j]]=j;
	int ans=0;
	vector<int> indi(m+1,0);
	for(int i=1; i<=n; i++)
		if(!b[i])
		{
			b[i]=1;
			for(int j=1; j<=m; j++)
				indi[j]=ra[j][i];
			while(true)
			{
				bool bol=0;
				for(int j=1; j<=m; j++)
				{
					indi[j]++;
					if(indi[j]>n)
						bol=1;
				}
				int te=a[1][indi[1]];
				for(int j=1; j<=m; j++)
					if(a[j][indi[j]]!=te)
						bol=1;
				if(bol)
					break;
				b[te]=-1;
				b[i]++;
			}
		}
	for(int i=1; i<=n; i++)
		ans+=(b[i]*(b[i]+1))/2;
	cout<<ans<<endl;
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