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

int main()
{jizz
	ll la,ra,ta,lb,rb,tb,g,s,ans=0,k;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	g=__gcd(tb,ta);
	s=(la-lb%ta+ta)%ta;
	k=((((s-1)/g)+1)*g+lb)%ta;
	if(k>=la)
		ans=max(min(ra-k+1,rb-lb+1),ans);
	
	s=(lb-la%tb+tb)%tb;
	k=((((s-1)/g)+1)*g+la)%tb;
	if(k>=lb)
		ans=max(min(rb-k+1,ra-la+1),ans);
	
	cout << ans << '\n';
}