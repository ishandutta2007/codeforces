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

ll arr[1005];

int main()
{jizz
	ll n,ans=1e18,t=-1;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<=100;++i)
	{
		ll tmp=0;
		for(int j=1;j<=n;++j)
		{
			if(arr[j]>i) tmp+=arr[j]-(i+1);
			else if(arr[j]<i) tmp+=i-1-arr[j];
		}
		if(ans>tmp) ans=tmp,t=i;
	}
	cout << t << " " << ans << "\n";
}