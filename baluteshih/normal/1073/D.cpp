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

ll arr[200005],arr2[200005],bit[200005],bit2[200005],n,cnt,sum;

void modify(ll x,ll v)
{
	ll t=v;
	v=v-arr[x],arr[x]=t,sum+=v;
	for(;x<=n;x+=x&-x) bit[x]+=v;
}

void modify2(ll x,ll v)
{
	ll t=v;
	v=v-arr2[x],arr2[x]=t,cnt+=v;
	for(;x<=n;x+=x&-x) bit2[x]+=v;
}

ll query(ll x)
{
	ll re=0;
	for(;x;x-=x&-x) re+=bit[x];
	return re;
}

ll query2(ll x)
{
	ll re=0;
	for(;x;x-=x&-x) re+=bit2[x];
	return re;
}

int main()
{jizz
	ll t,ans=0,x,l,r,s;
	cin >> n >> t;
	for(int i=1;i<=n;++i)
		cin >> x,modify(i,x),modify2(i,1);
	while(cnt)
	{
		x=t/sum,t-=sum*x,ans+=x*cnt,l=1;
		while(l<=n&&cnt)
		{
			x=l,r=n+1,s=query(l-1);
			while(x<r)
			{
				ll m=x+r>>1;
				if(query(m)-s>t) r=m;
				else x=m+1;
			}
			t-=query(x-1)-s,ans+=query2(x-1)-query2(l-1);
			if(x==n+1) break;
			modify(x,0),modify2(x,0);
			l=x+1;
		}
	}
	cout << ans << "\n";
}