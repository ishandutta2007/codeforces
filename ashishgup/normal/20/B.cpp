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
	ll ans=0;
	vector<double> roots;
	if(c==0)
	{
		if(b==0)
		{
			if(a!=0)
			{	
				ans=1;
				roots.push_back(0);
			}
			else
			{
				ans=-1;
			}
		}
		else if(a==0)
		{
			ans=1;
			roots.push_back(0);
		}
		else
		{
			ans=2;
			roots.push_back(0);
			roots.push_back(((-1.0*b)/a));
		}
	}
	else if(b==0)
	{
		if(a==0)
		{
			ans=0;
		}
		else
		{
			if(a>0&&c<0||a<0&&c>0)
			{
				ans=2;
				double root=sqrt((-1.0*c)/a);
				roots.push_back(root);
				roots.push_back(-1*root);
			}
			else
			{
				ans=0;
			}
		}
	}
	else if(a==0)
	{
		ans=1;
		roots.push_back((-1.0*c)/b);
	}
	else
	{
		ll disc=b*b-4*a*c;
		if(disc<0)
		{
			ans=0;
		}
		else if(disc==0)
		{
			ans=1;
			double root=((-1.0*b)/(2*a));
			roots.push_back(root);
		}
		else
		{
			ans=2;
			double discr=sqrt(disc);
			double root1=(double)(-b+discr)/(2*a);
			double root2=(double)(-b-discr)/(2*a);
			roots.push_back(root1);
			roots.push_back(root2);
		}
	}
	cout<<ans<<endl;
	if(ans>0)
	{
		sort(roots.begin(),roots.end());
		cout<<fixed<<showpoint<<setprecision(6);
		for(ll i=0;i<ans;i++)
		{
			cout<<roots[i]<<endl;
		}
	}
	return 0;
}