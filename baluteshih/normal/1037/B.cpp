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
	ll n,s,ans=0;
	cin >> n >> s;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	sort(arr,arr+n);
	if(s==arr[n/2])
		return cout << "0\n",0;
	if(s>arr[n/2])
	{
		for(int i=n/2;i<n && arr[i]<s;++i)
			ans+=s-arr[i];
		cout << ans << "\n";
	}
	else
	{
		for(int i=n/2;i>=0 && arr[i]>s;--i)
			ans+=arr[i]-s;
		cout << ans << "\n";
	}
}