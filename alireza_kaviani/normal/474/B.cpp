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
#define endt                        '\t'

int bs(int a[],int x,int n)
{
	if(a[0]>x) return 0;
	int l=0,r=n-1;
	
	while(true)
	{
		int mid=(l+r)/2;
		
		if(a[mid]==x)return mid;
		if(a[mid]>x)r=mid;
		if(a[mid]<x)l=mid;
		
		if(r<=l+1)
		{
			if(a[l]==x)
			{
				return l;
			}
			return l+1;
		}
	}
}

int main()
{
	int n,m;
	cin >> n;
 
	int a[n];
	int temp=0;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		a[i]=temp+t;
		temp=a[i];
	}
	
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int t;
		cin >> t;
 
		cout << bs(a,t,n)+1 << endl;
	}
	
	return 0;
}