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

const ll MOD=998244353;
ll b[200005];

ll powm(ll a,ll n)
{
	ll re=1;
	for(;n;n>>=1,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

int main()
{jizz
	ll n,m,A,ans=1,tmp,two=(MOD+1)/2;
	cin >> n >> m >> A;
	for(int i=1;i<=m;++i)
	{
		cin >> b[i];
		tmp=powm(A,b[i]-b[i-1]);
		ans=ans*tmp%MOD*(tmp+1)%MOD*two%MOD;
	}
	tmp=powm(A,n-2*b[m]);
	cout << ans*tmp%MOD << "\n";
}