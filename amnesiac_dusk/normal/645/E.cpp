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

int ct[26];
int lol[26];
void solve()
{
	int m,k;
	cin>>m>>k;
	for(int i=0; i<26; i++)
		ct[i]=-i-1;
	string s;
	cin>>s;
	ll sum;
	for(int i=0; i<s.length(); i++)
	{
		sum=0;
		for(int j=0; j<k; j++)
			sum+=lol[j];
		ct[s[i]-'a']=i;
		lol[s[i]-'a']=(sum+1)%mod;
	}
	int mini=10000000,minind=0;
	for(int i=s.length(); i<s.length()+m; i++)
	{
		sum=0;
		mini=10000000;
		for(int j=0; j<k; j++)
		{
			sum+=lol[j];
			if(mini>ct[j])
			{
				mini=ct[j];
				minind=j;
			}
		}
		lol[minind]=(sum+1)%mod;
		ct[minind]=i;
	}
	sum=0;
	for(int i=0; i<k; i++)
		sum+=lol[i];
	cout<<(sum+1)%mod<<endl;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	// cin >> t;
		solve();
	return 0;
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