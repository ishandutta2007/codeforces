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

ll per[300005],pl[300005];
vector<pll> v;

void Swap(ll a,ll b)
{
	v.pb(MP(a,b));
	pl[per[a]]=b,pl[per[b]]=a;
	swap(per[a],per[b]);
}

int main()
{jizz
	ll n;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> per[i],pl[per[i]]=i;
	for(int i=2;i<=n/2;++i)
	{
		if(n-pl[i]>pl[i]-1)
			Swap(n,pl[i]);
		else	
			Swap(1,pl[i]),Swap(1,n);
		Swap(n,i);
	}
	for(int i=n/2+1;i<n;++i)
	{
		if(n-pl[i]>pl[i]-1)
			Swap(n,pl[i]),Swap(1,n);
		else
			Swap(1,pl[i]);
		Swap(1,i);
	}
	if(pl[1]!=1)
		Swap(1,n);
	cout << v.size() << "\n";
	for(auto i:v)
		cout << i.F << " " << i.S << "\n";
}