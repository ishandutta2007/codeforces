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
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#ifdef rd
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
typedef long long ll;
const ll inf=1e18;
const int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

const int N=3005;
char a[N][N];
int dp1[N][N],dp2[N][N];
void solve()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf(" %s",a[i]+1);
	if(a[2][1]=='.')
		dp1[2][1]=1;
	if(a[1][2]=='.')
		dp2[1][2]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			dp1[i][j]-=(dp1[i][j]>=mod)?mod:0;
			dp2[i][j]-=(dp2[i][j]>=mod)?mod:0;
			if(a[i+1][j]!='#')
			{
				dp1[i+1][j]+=dp1[i][j];
				dp2[i+1][j]+=dp2[i][j];
			}
			if(a[i][j+1]!='#')
			{
				dp1[i][j+1]+=dp1[i][j];
				dp2[i][j+1]+=dp2[i][j];
			}
		}
	int ans=((((1LL*dp2[n-1][m])*dp1[n][m-1])-((1LL*dp1[n-1][m])*dp2[n][m-1]))%mod+mod)%mod;
	printf("%d\n",ans);
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin.exceptions(cin.failbit);
//	srand(chrono::steady_clock::now().time_since_epoch().count());
//	cout<<fixed<<setprecision(12);
//	int t=1;
//	auto clk=clock();
//	cin>>t;
//	while(t--)
		solve();
//#ifdef rd
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
//#endif
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