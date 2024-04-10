#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;
const double pi=acosl(-1.0l);

int n, r;

int32_t main()
{
	IOS;
	cin>>n>>r;
	double theta=pi/n;
	double R=r*sinl(theta)/(1-sinl(theta));
	cout<<fixed<<setprecision(12)<<R;
	return 0;
}