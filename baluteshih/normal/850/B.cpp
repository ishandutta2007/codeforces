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

ll cnt[2000005],icnt[2000005],prime[2000005];

int main()
{jizz
	ll n,x,y,d,l,mx=0,t,ans=1e18;
	cin >> n >> y >> x,d=y/x+1;
	while(n--)
		cin >> t,++cnt[t],mx=max(mx,t);
	mx<<=1,icnt[1]=cnt[1];
	for(ll i=2;i<=mx;++i)
		icnt[i]=i*cnt[i]+icnt[i-1],cnt[i]+=cnt[i-1];
	for(ll i=2;i<=mx;++i)
		if(!prime[i])
		{
			t=0,l=max(-d,-i);
			for(ll j=i;j<=mx;prime[j]=1,j+=i)
				t+=x*(j*(cnt[j]-cnt[j+l])-icnt[j]+icnt[j+l])+y*(cnt[j+l]-cnt[j-i]);
			ans=min(t,ans);
		}
	cout << ans << "\n";
}