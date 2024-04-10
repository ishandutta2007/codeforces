#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll; 

int main()
{jizz
	ll n,h,a,b,k,ta,fa,tb,fb,ans;
	cin >> n >> h >> a >> b >> k;
	while(k--)
	{
		cin >> ta >> fa >> tb >> fb;
		if(ta>tb) swap(ta,tb),swap(fa,fb);
		if(ta==tb)
		{
			cout << (ll)abs(fa-fb) << "\n";
			continue;
		}
		if(a<=fa && fa<=b)
			cout << tb-ta+(ll)abs(fa-fb) << "\n";
		else if((ll)abs(fa-a)<(ll)abs(fa-b))
			cout << (ll)abs(fa-a)+tb-ta+(ll)abs(a-fb) << "\n";
		else
			cout << (ll)abs(fa-b)+tb-ta+(ll)abs(b-fb) << "\n";
	}
}