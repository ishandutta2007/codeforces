#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define MP make_pair
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

const ll MOD=1e9+9;
string s;

ll powm(ll a,ll n)
{
	ll re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

ll what(ll a,ll n)
{
	ll re=0,w=1,i=1;
	for(;n;n/=2,w=(w+w*a)%MOD,a=a*a%MOD)
		if(n&1) re=(re+w*i)%MOD,i=i*a%MOD;
	return re;
}

int main()
{jizz
	ll n,a,b,k,i,j,now,x,ans=0,t,w,z,y;
	cin >> n >> a >> b >> k,x=powm(a,MOD-2),w=powm(b*x%MOD,k);
	cin >> s;
	for(ans=0,i=0,t=1,now=0;i<k;++i,t=t*b%MOD*x%MOD)
		now=(now+t*(s[i]=='+' ? 1 : -1))%MOD;
	now=now*what(w,n/k)%MOD;
	w=powm(b*x%MOD,n/k*k);
	for(i=n/k*k,j=0;i<=n;++i,w=w*b%MOD*x%MOD,++j)
		now=(now+w*(s[j]=='+' ? 1 : -1))%MOD;
	cout << (now*powm(a,n)%MOD+MOD)%MOD << "\n";
}