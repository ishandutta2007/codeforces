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

ll arr[200005],arr2[200005],ti[200005];

int main()
{jizz
	ll n,ans1=0,pl=-1,ans2=1e9;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	for(int i=0;i<n;++i)
	{
		cin >> arr2[i];
		if(arr2[i]) ans1=max(ans1,i+2-arr2[i]);
		ti[arr2[i]]=i+1;
		if(arr2[i]==1) pl=i;
	}
	if(~pl)
	{
		for(int i=pl+1;i<n&&(~pl);++i)
			if(arr2[i]!=arr2[i-1]+1) pl=-1;
		if(~pl)
		{
			for(int i=n-pl+1;i<=n&&(~pl);++i)
				if(ti[i]>=i-(n-pl)) pl=-1;
			if(~pl)
				ans2=pl;
		}
	}	
	cout << min(ans1+n,ans2) << "\n";
}