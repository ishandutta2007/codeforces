#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int x, y, z, t1, t2, t3;
	cin>>x>>y>>z>>t1>>t2>>t3;
	//Lift goes to X
	int ans=abs(z-x)*t2;
	//Door opens and closes
	ans+=t3*3;
	//Lift goes to Y
	ans+=abs(y-x)*t2;
	int stairs=t1*abs(x-y);
	if(stairs>=ans)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}