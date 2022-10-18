#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[200005],arr2[200005];

int main()
{jizz
	ll n,m,ta,tb,k,ans=0;
	cin >> n >> m >> ta >> tb >> k;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	for(int i=0;i<m;++i)
		cin >> arr2[i];
	if(k>=n||k>=m)
		return cout << "-1\n",0;
	for(int i=0;i<=k;++i)
	{
		int p=lower_bound(arr2,arr2+m,arr[i]+ta)-arr2;
		if(p+k-i>=m)
			return cout << "-1\n",0;
		ans=max(ans,arr2[p+k-i]+tb);
	}
	cout << ans << "\n";
}