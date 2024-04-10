#include <bits/stdc++.h>
using namespace std;

typedef long long		ll;
typedef long double 		ld;
typedef pair<int,int>		pii;
typedef pair<ll,ll> 		pll;
typedef pair<double,double> 	pdd;
typedef pair<ld,ld>         	pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>		plll;
typedef pair<pdd,double>	pddd;
typedef pair<pld,ld>		pldd;
typedef vector<int>         	vi;
typedef vector<ll>          	vll;
typedef vector<double>      	vd;
typedef vector<ld>		vld;
typedef vector<pii> 	    	vpii;
typedef vector<pll> 	    	vpll;
typedef vector<pdd> 	    	vpdd;
typedef vector<pld>		vpld;
typedef vector<piii>		vpiii;
typedef vector<plll>		vplll;
typedef vector<pddd>		vpddd;
typedef vector<pldd>		vpldd;

#define all(x)       (x).begin(),(x).end()
#define Sort(x)      sort(all((x)))
#define pb           push_back
#define ppb          pop_back
#define pf           push_front
#define ppf          pop_front
#define X            first
#define Y            second
#define MP	         make_pair

int main()
{
	double a=0 ,b=0 , n;
	
	for(int i=0;i<3;i++)
	{
		int t;
		cin >> t;
		a+=t;
	}
	for(int i=0;i<3;i++)
	{
		int t;
		cin >> t;
		b+=t;
	}
	cin >> n;
	
	if(n>=ceil(a/5) + ceil(b/10))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}