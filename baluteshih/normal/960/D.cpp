#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;

ll arr[70];

ll cross(ll a,ll b,ll MOD)
{
	ll re=0;
	for(;b;b/=2,a=(a+a)%MOD)
		if(b&1) re=(re+a)%MOD;
	return re;
}

int main()
{jizz
	ll n,i,k,x,d,t;
	cin >> n;
	while(n--)
	{
		cin >> k;
		if(k==1) cin >> x >> d,i=__lg(x),arr[i]=(arr[i]+d)%(1LL<<i);
		else if(k==2)
			for(cin >> x >> d,i=__lg(x),t=1;i<=63;++i,t<<=1) 
				arr[i]=(arr[i]+cross(d,t,1LL<<i))%(1LL<<i);
		else
		{
			for(cin >> x,i=__lg(x),t=1LL<<i,x=(x+arr[i])%t+t;x;x/=2,--i,t>>=1)
				cout << (x-arr[i]+t)%t+t << " ";
			ET;
		}
	}
}