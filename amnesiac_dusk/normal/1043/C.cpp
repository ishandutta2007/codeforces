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

int anses[1001];
signed main()
{
	IO;
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0; i<n-1; i++) {
		if(s[i]=='a'&&s[i+1]=='b')
			anses[i]=1;
		if(s[i]=='b'&&s[i+1]=='a')
			anses[i]=1;
	}
	if(s[n-1]=='a')
		anses[n-1]=1;
	for(int i=0; i<n; i++)
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