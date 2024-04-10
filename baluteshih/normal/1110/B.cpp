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

ll arr[100005];
priority_queue<ll> pq;

int main()
{jizz
	ll n,m,k,ans;
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	ans=arr[n]-arr[1]+1;
	for(int i=1;i<n;++i)
		pq.push(arr[i+1]-arr[i]-1);
	while(--k)
		ans-=pq.top(),pq.pop();
	cout << ans << "\n";
}