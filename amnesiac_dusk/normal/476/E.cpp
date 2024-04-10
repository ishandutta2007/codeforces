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

int anses[2001];
int dp[2001][2001];
signed main()
{
	IO;
	string s,p;
	cin>>s>>p;
	int mm=0;
	int ii,jj;
	for(ii=0,jj=0; ii<s.length(); ii++)
		if(s[ii]==p[jj%p.length()])
			jj++;
	mm=jj/p.length();
	for(ii=s.length(); ;ii--)
	{
		anses[ii]=(s.length()-ii)/p.length();
		if(!(s.length()-ii-mm*p.length()))
			break;
	}
	for(int i=0; i<=s.length(); i++)
		for(int j=0; j<=s.length(); j++)
			dp[i][j]=100000000;
	dp[0][0]=0;
	for(int i=0; i<s.length(); i++)
		for(int j=0; j<=s.length(); j++)
		{
			if(s[i]==p[j%p.length()])
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			if(!(j%p.length()))
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
//			else
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		}
//	for(int i=1; i<=s.length(); i++)
//		cout<<dp[s.length()][i]<<endl;
	for(int i=0; i<=mm*p.length(); i+=p.length())
		anses[dp[s.length()][i]]=i/p.length();
	for(int i=1; i<=ii; i++)
		anses[i]=max(anses[i],anses[i-1]);
	for(int i=0; i<=s.length(); i++)
		cout<<anses[i]<<" ";
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