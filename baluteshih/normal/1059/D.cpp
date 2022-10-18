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
typedef pair<double,double> pdd;

pdd arr[100000];
const double eps=1e-8;
int n,cas;

double f(double x)
{
	double mx=0;
	for(int i=0;i<n;++i)
	{
		double a=(arr[i].F-x)*(arr[i].F-x)+arr[i].S*arr[i].S;
		mx=max(mx,a/fabs(arr[i].S)/2);
	}
	return mx;
}

int main()
{jizz
	double l=-2e7,r=2e7;
	cin >> n;
	cin >> arr[0].F >> arr[0].S;
	if(arr[0].S>0) cas=1;
	else cas=-1;
	for(int i=1;i<n;++i)
	{
		cin >> arr[i].F >> arr[i].S;
		if(cas==1 && arr[i].S<0)
			return cout << "-1\n",0;
		if(cas==-1 && arr[i].S>0)
			return cout << "-1\n",0;
	}
	while(r-l>eps)
	{
		double ml=(l+l+r)/3,mr=(l+r+r)/3;
		if(f(ml)>f(mr)) l=ml;
		else r=mr;
	}
	cout << fixed << setprecision(10) << f(l) << "\n";
}