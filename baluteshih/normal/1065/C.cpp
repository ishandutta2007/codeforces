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

ll arr[200000]; 

int main()
{jizz
	ll n,k,ans=0,cost,tmp;
	cin >> n >> k;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	sort(arr,arr+n),cost=0;
	for(int i=arr[n-1]-1,j=n-1;i>=0;--i)
	{
		while(j>=0&&arr[j]>i) --j;
		if(j<0) break;
		tmp=n-1-j;
		if(cost+tmp>k)
			++ans,cost=0;
		cost+=tmp;
	}
	cout << ans+(cost>0) << "\n";
}