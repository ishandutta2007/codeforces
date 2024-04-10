#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		double d;
		cin>>d;
		double val=d*d - 4*d;
		if(val<0)
		{
			cout<<"N"<<endl;
			continue;
		}
		double x=(d + sqrtl(val))/2.0;
		if(x<0)
		{
			cout<<"N"<<endl;
			continue;
		}
		double y=0;
		if(x>0)
			y=d/x;
		cout<<fixed<<setprecision(12)<<"Y "<<x<<" "<<y<<endl;
	}	
	return 0;
}