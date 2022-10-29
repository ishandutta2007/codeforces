#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll m;
	cin>>m;
	vector<ll> u;
	vector<ll> p;
	for(ll i=0;i<m;i++)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(s[0]=='U')
		{
			u.pb(n);
		}
		else
		{
			p.pb(n);
		}
	}
	sort(u.begin(),u.end());
	sort(p.begin(),p.end());
	ll usize=u.size();
	ll psize=p.size();
	ll uindex=0;
	ll counta=0;
	ll ans1=0;
	ll ans2=0;
	ll i=0;
	for(i=0;i<usize;i++)
	{
		if(counta>=a)
		{
			break;
		}
		ans1++;
		ans2+=u[i];
		counta++;
	}
	uindex=i;
	ll countb=0;
	ll pindex=0;
	for(i=0;i<psize;i++)
	{
		if(countb>=b)
		{
			break;
		}
		ans1++;
		ans2+=p[i];
		countb++;
	}
	pindex=i;
	while(c>0&&(pindex<psize||uindex<usize))
	{
		if((pindex<psize)&&(uindex<usize))
		{
			if(u[uindex]<=p[pindex])
			{
				ans1++;
				ans2+=u[uindex];
				uindex++;
			}
			else
			{
				ans1++;
				ans2+=p[pindex];
				pindex++;
			}
		}
		else if(pindex<psize)
		{
			ans1++;
			ans2+=p[pindex];
			pindex++;
		}
		else
		{
			ans1++;
			ans2+=u[uindex];
			uindex++;
		}
		c--;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}