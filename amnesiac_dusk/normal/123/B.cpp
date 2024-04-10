/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
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
#define double long double
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


signed main()
{
	IO;
	int a,b,x1,y1,x2,y2;
	cin>>a>>b>>x1>>y1>>x2>>y2;
	int te1=(x1+y1+(2*a)*2000000000)/(2*a);
	int te2=(x1-y1+(2*b)*2000000000)/(2*b);
	int te3=(x2+y2+(2*a)*2000000000)/(2*a);
	int te4=(x2-y2+(2*b)*2000000000)/(2*b);
	cout<<abs(te1-te3)+abs(te2-te4)-min(abs(te1-te3),abs(te2-te4))<<endl;
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