#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[100005],ans[100005];
priority_queue<pll,vector<pll>,greater<pll>> pq,query;
vector<ll> tmp;

int main()
{jizz
	ll n,q,l,r,nw=0,nans=0;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	sort(arr,arr+n),n=unique(arr,arr+n)-arr,nans=n;
	for(int i=0;i+1<n;++i)
		pq.push(MP(arr[i+1]-arr[i],i));
	cin >> q;
	for(int i=0;i<q;++i)
		cin >> l >> r,query.push(MP(r-l,i));
	while(!query.empty())
	{
		tmp.clear();
		ll x=query.top().F;
		tmp.pb(query.top().S),query.pop();
		while(!query.empty()&&query.top().F==x)
			tmp.pb(query.top().S),query.pop();
		nans+=(x-nw)*n,nw=x;
		while(!pq.empty()&&pq.top().F<=x)
			nans-=x-pq.top().F+1,pq.pop(),--n;
		for(auto i:tmp)
			ans[i]=nans;
	}
	for(int i=0;i<q;++i)
		cout << ans[i] << " \n"[i==q-1]; 
}