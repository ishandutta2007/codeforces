#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll sum[200005];

int main() 
{jizz
	ll n,q,l,r,nw,x,tmp;
	cin >> n >> q;
	for(int i=1;i<=n;++i)
		cin >> sum[i],sum[i]+=sum[i-1];
	for(nw=1,tmp=0;q--;)
	{
		cin >> x;
		l=nw,r=n+1;
		while(l<r)
		{
			ll m=l+r>>1;
			if(sum[m]-sum[nw-1]-tmp<=x) l=m+1;
			else r=m;
		}
		tmp=x-(sum[l-1]-sum[nw-1]-tmp);
		if(l==n+1) nw=1,tmp=0;
		else nw=l;
		cout << n-nw+1 << "\n";
	}
}