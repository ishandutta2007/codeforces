#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

struct node
{
	ll d,f,t,c;
};

bool comp(node n1, node n2)
{
	if(n1.d<n2.d)
	{
		return true;
	}
	else if(n1.d == n2.d)
	{
		return n1.c<n2.c;
	}
	else
	{
		return false;
	}
}

bool comp2(node n1, node n2)
{
	if(n1.d<n2.d)
	{
		return true;
	}
	else if(n1.d == n2.d)
	{
		return n1.c>n2.c;
	}
	else
	{
		return false;
	}
}

node v[N];
ll n,m,k;
int main()
{
	IOS;
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++)
	{
		cin>>v[i].d>>v[i].f>>v[i].t>>v[i].c;
	}
	sort(v,v+m,comp);
	vll prefmin(1e6+5,1e11);
	vll sufmin(1e6+5,1e11);
	multiset<ll> arrival;
	ll sum=0;
	ll ind=0;
	vll a(n+1,-1);
	while(arrival.size()!=n && ind<m)
	{
		if(v[ind].t==0)
		{
			if(a[v[ind].f]==-1)
			{
				arrival.insert(v[ind].c);
				sum+=v[ind].c;
				a[v[ind].f]=v[ind].c;
			}
			else
			{
				if(v[ind].c<a[v[ind].f])
				{
					arrival.erase(arrival.find(a[v[ind].f]));
					arrival.insert(v[ind].c);
					sum+=v[ind].c;
					sum-=a[v[ind].f];
					a[v[ind].f]=v[ind].c;
				}
			}
		}
		ind++;
	}
	if(arrival.size()!=n)
	{
		cout<<"-1";
		return 0;
	}
	ll start=ind-1;
	prefmin[v[start].d+1]=sum;
	ll currentst=v[start].d+1;
	while(ind<m)
	{
		if(v[ind].t==0)
		{
			if(a[v[ind].f]>v[ind].c)
			{
				sum+=v[ind].c;
				sum-=a[v[ind].f];
				a[v[ind].f]=v[ind].c;
				for(ll i=currentst;i<=v[ind].d;i++)
				{
					prefmin[i]=min(prefmin[i-1],prefmin[i]);
				}
				prefmin[v[ind].d+1]=sum;
				currentst=v[ind].d+1;
			}
		}
		ind++;
	}
	for(ll i=currentst+1;i<=1e6;i++)
	{
		prefmin[i]=prefmin[i-1];
	}
/*	for(ll i=1;i<=20;i++)
	{
		cout<<prefmin[i]<<" ";
	}cout<<endl;*/
	sort(v,v+m,comp2);
	multiset<ll> departure;
	sum=0;
	ind=m-1;
	vll b(n+1,-1);
	while(departure.size()!=n && ind>=0)
	{
		if(v[ind].f==0)
		{
			if(b[v[ind].t]==-1)
			{
				departure.insert(v[ind].c);
				sum+=v[ind].c;
				b[v[ind].t]=v[ind].c;
			}
			else
			{
				if(v[ind].c<b[v[ind].t])
				{
					departure.erase(departure.find(b[v[ind].t]));
					departure.insert(v[ind].c);
					sum+=v[ind].c;
					sum-=b[v[ind].t];
					b[v[ind].t]=v[ind].c;
				}
			}
		}
		ind--;
	}
	if(departure.size()!=n)
	{
		cout<<"-1";
		return 0;
	}
	ll end=ind+1;
	if(v[end].d - v[start].d -1 < k)
	{
		cout<<"-1";
		return 0;
	}
	sufmin[v[end].d-1]=sum;
	currentst=v[end].d-1;
	while(ind>=0)
	{
		if(v[ind].f==0)
		{
			if(b[v[ind].t]>v[ind].c)
			{
				sum+=v[ind].c;
				sum-=b[v[ind].t];
				b[v[ind].t]=v[ind].c;
				for(ll i=currentst;i>=v[ind].d;i--)
				{
					sufmin[i]=min(sufmin[i-1],sufmin[i]);
				}
				sufmin[v[ind].d-1]=sum;
				currentst=v[ind].d-1;
			}
		}
		ind--;
	}
	for(ll i=currentst-1;i>=1;i--)
	{
		sufmin[i]=sufmin[i+1];
	}
/*	for(ll i=1;i<=20;i++)
	{
		cout<<sufmin[i]<<" ";
	}cout<<endl;*/
	ll ans=LLONG_MAX;
	for(ll i=v[start].d+1;i+k-1<v[end].d;i++)
	{
		ans=min(prefmin[i]+sufmin[i+k-1],ans);
	}
	cout<<ans;
	return 0;
}