#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map<ll,ll> mp,fac3,fac4;
const ll MOD=998244353,MAXC=2e18,C=1300000,CC=1500000000;
ll prime[C+1];
vector<ll> p,u,v,tmp;

bool MM(ll a)
{
	for(ll i=2;i*i<=a;++i)
		if(a%i==0) return 0;
	return 1;
}

void fre(ll t)
{
	u.pb(t);
	tmp.clear();
	vector<ll> f;
	for(ll i:v)
		if(i%t==0)
		{
			++mp[t],++mp[i/t];
			if(mp[i/t]==1)
				f.pb(i/t);
		}
		else tmp.pb(i);
	v.swap(tmp);
	for(ll i:f)
		fre(i);
}

int main()
{jizz
	ll n,a,ans=1,x,l,r,t;
	for(ll i=2;i<=C;++i)
	{
		if(!prime[i]) p.pb(i);
		for(ll j:p)
		{
			if(i*j>C) break;
			prime[i*j]=1;
			if(i%j==0) break;
		}
	}
	for(ll i=2;i*i*i<=MAXC;++i)
		if(!prime[i])
			fac3[i*i*i]=i;
	for(ll i=2;i*i*i*i<=MAXC;++i)
		if(!prime[i])
			fac4[i*i*i*i]=i;
	cin >> n;
	while(n--)
	{
		cin >> a;
		for(l=2,r=CC;l<r;)
		{
			ll m=(l+r)/2+1;
			if(m*m<=a) l=m;
			else r=m-1;
		}
		x=l;
		if(MM(x)&&x*x==a)
		{
			mp[x]+=2;
			if(mp[x]==2)
				fre(x);
		}
		else if((x=fac3[a])!=0)
		{
			mp[x]+=3;
			if(mp[x]==3)
				fre(x);
		}
		else if((x=fac4[a])!=0)
		{
			mp[x]+=4;
			if(mp[x]==4)
				fre(x);
		}
		else
		{
			x=0;
			for(ll i:u)
				if(a%i==0)
				{
					x=1;
					++mp[i],++mp[a/i];
					if(mp[a/i]==1)
						fre(a/i);
					break;
				}
			if(!x)
			{
				t=1;
				for(ll i:v)
				{
					ll gg=__gcd(i,a);
					if(gg!=1&&gg!=a)
					{
						t=gg;
						break;
					}
				}
				if(t==1)
				{
					v.pb(a);
					continue;
				}
				++mp[t],++mp[a/t];
				if(mp[a/t]==1) 
					fre(a/t);
				fre(t);
			}
		}
	}
	for(auto p:mp)
		ans=ans*(p.S+1)%MOD;
	sort(ALL(v));
	for(ll i=0,j=0;i<v.size();i=j)
	{
		t=0;
		while(j<v.size()&&v[i]==v[j])
			++t,++j;
		ans=ans*(t+1)%MOD*(t+1)%MOD;
	}
	cout << ans << "\n";
}