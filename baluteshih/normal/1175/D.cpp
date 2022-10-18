#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[300005];

int main()
{jizz
	ll n,k,ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;++i)
		cin >> arr[i],arr[i]+=arr[i-1];
	sort(arr+1,arr+n),ans=arr[n]*k;
	for(int i=1;i<k;++i)
		ans-=arr[i];
	cout << ans << "\n";
}