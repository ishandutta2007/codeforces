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

ll arr[100005];
const ll INF=1e18;
vector<ll> ans,fac[200005];

int main()
{jizz
	ll n,s=0,x;
	cin >> n;
	for(int i=1;i<=200000;++i)
		for(int j=i;j<=200000;j+=i)
			fac[j].pb(i);
	for(int i=0;i<n/2;++i)
	{
		cin >> arr[i];
		x=INF;
		for(ll j:fac[arr[i]])
			if(j*j>arr[i]) break;
			else
			{
				if((arr[i]/j+j)%2==0&&((arr[i]/j-j)/2)*((arr[i]/j-j)/2)>s)
					x=min(x,((arr[i]/j-j)/2)*((arr[i]/j-j)/2)-s);
			}
		if(x==INF)
			return cout << "No\n",0;
		ans.pb(x),ans.pb(arr[i]),s+=x+arr[i];
	}
	cout << "Yes\n";
	for(ll i:ans)
		cout << i << " ";
	ET;
}