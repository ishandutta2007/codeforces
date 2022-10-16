/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
//#define endl '\n'
#endif
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int dp[2][501][501];
string te[501];
int modu;
signed main()
{
	IO;
	int n,ke;
	cin>>n>>ke>>modu;
	for(int i=0; i<ke; i++)
		cin>>te[i];
	int singles=0,doubles=0;
	int tes=0;
	for(int i=0; i<n; i++)
	{
		int sum=0;
		for(int j=0; j<ke; j++)
			sum+=(te[j][i]=='1');
		if(sum==0)
			doubles++;
		if(sum==1)
			singles++;
		if(sum>2)
		{
			cout<<0<<endl;
			return 0;
		}
		tes+=sum;
	}
	if(ke*2!=tes)
	{
		cout<<0<<endl;
		return 0;
	}
	dp[0][0][0]=1;
	int temp;
	for(int i=1; i<=n-ke; i++)
	{
		temp=min(2*i,n);
		for(int j=2; j<=temp; j++)
		{
			int k=i-j/2;
//			for(int k=0; k<=i; k++)
				dp[1][j][k]=(dp[1][j][k]+dp[0][j-2][k]*((j*(j-1))>>1));
		}
		for(int j=0; j<=temp; j++)
		{
			int k=i-j/2;
//			for(int k=2; k<=i; k++)
				dp[1][j][k]=(dp[1][j][k]+dp[0][j+2][k-2]*((k*(k-1))>>1));
		}
		for(int j=1; j<=temp; j++)
		{
			int k=i-j/2;
//			for(int k=1; k<=i; k++)
				dp[1][j][k]=(dp[1][j][k]+(j*k)*dp[0][j][k-1]);
		}
		for(int j=0; j<=temp; j++)
		{
			int k=i-j/2;
//			for(int k=0; k<=i; k++)
//			{
				dp[0][j][k]=dp[1][j][k]%modu;
				dp[1][j][k]=0;
//			}
		}
	}
	cout<<dp[0][singles][doubles]<<endl;
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