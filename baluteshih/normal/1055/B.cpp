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

ll boss[100005],arr[100005],ans;

ll finds(ll x)
{
	if(boss[x]==x) return x;
	return boss[x]=finds(boss[x]);
}

void Union(ll a,ll b)
{
	a=finds(a),b=finds(b);
	if(a==b) return;
	--ans;
	boss[a]=b;
}

int main()
{jizz
	ll n,m,l,k,x;
	cin >> n >> m >> l;
	for(int i=1;i<=n;++i)
	{
		cin >> arr[i],boss[i]=i;
		if(arr[i]>l)
		{
			++ans;
			if(arr[i-1]>l) Union(i,i-1);
		}
	}
	while(m--)
	{
		cin >> k;
		if(k==0)
			cout << ans << "\n";
		else
		{
			cin >> x >> k;
			if(arr[x]<=l&&arr[x]+k>l)
			{
				++ans;
				if(arr[x-1]>l)
					Union(x,x-1);
				if(arr[x+1]>l)
					Union(x,x+1);
			}
			arr[x]+=k;
		}
	}
}