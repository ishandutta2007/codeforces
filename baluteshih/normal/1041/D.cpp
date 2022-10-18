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

pll seg[200000];
deque<ll> dq;

int main()
{jizz
	ll ans,n,h,cnt=0,tmp=0;
	cin >> n >> h;
	for(int i=0;i<n;++i)
		cin >> seg[i].F >> seg[i].S;
	tmp=ans=seg[0].S-seg[0].F+h,dq.pb(0LL);
	for(ll i=1;i<n;++i)
	{
		dq.pb(i),cnt+=seg[i].F-seg[i-1].S,tmp+=seg[i].S-seg[i].F;
		while(cnt>=h) cnt-=seg[dq[1]].F-seg[dq[0]].S,tmp-=seg[dq[0]].S-seg[dq[0]].F,dq.pop_front();
		ans=max(ans,tmp);
	}
	cout << ans << "\n";
}