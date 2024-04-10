#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>                plll;
typedef pair<pdd,double>            pddd;
typedef pair<pld,ld>                pldd;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<double>              vd;
typedef vector<ld>                  vld;
typedef vector<pii>                 vpii;
typedef vector<pll>                 vpll;
typedef vector<pdd>                 vpdd;
typedef vector<pld>                 vpld;
typedef vector<piii>                vpiii;
typedef vector<plll>                vplll;
typedef vector<pddd>                vpddd;
typedef vector<pldd>                vpldd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define M                           make_pair


int main()
{
	int n , m;
	cin >> n;
	
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	cin >> m;
	
	int b[m];
	for(int i=0;i<m;i++)
	{
		cin >> b[i];
	}
	
	sort(a,a+n);
	sort(b,b+m);
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(abs(a[i]-b[j])<=1)
			{
				ans++;
				a[i]=-1000;
				b[j]=-1000;
				break;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}