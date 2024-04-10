#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<ld> vld;

#define all(x)       (x).begin(),(x).end()
#define Sort(x)      sort(all((x)))
#define pb           push_back
#define ppb          pop_back
#define pf           push_front
#define ppf          pop_front
#define X            first
#define Y            second

bool a[10000000];

int main()
{
	a[1]=true;
	for(ll i=2;i*i<1e7;i++)
	{
		if(!a[i])
		{
			for(ll j=i*i;j<1e7;j+=i)
			{
				a[j]=true;
			}
		}
	}
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		ll t;
		cin >> t;
		
		ll sq=sqrt(t);
		if(sq*sq==t && a[sq]==false)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}