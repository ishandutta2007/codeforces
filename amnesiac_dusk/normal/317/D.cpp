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

int pows[31];
int grundies[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
signed main()
{
	IO;
	int n;
	cin>>n;
	for(int i=1; i<30; i++)
	{
		int te=(int)(pow(n,1.0/i)+1);
		while(powm(te,i,1e18)>n)
			te--;
		pows[i]=te-1;
//		if(!pows[i])
//			break;
//		cout<<pows[i]<<endl;
	}
	pows[1]++;
	for(int i=30; i>0; i--)
		for(int j=1; j<i; j++)
			pows[j]-=pows[i]*(i/j);
	int ans=0;
	for(int i=1; i<=29; i++)
		if(pows[i]&1)
			ans^=grundies[i];
	if(ans)
		cout<<"Vasya"<<endl;
	else
		cout<<"Petya"<<endl;
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