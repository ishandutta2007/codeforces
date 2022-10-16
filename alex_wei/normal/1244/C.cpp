#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p,w,d;
signed main()
{
	cin>>n>>p>>w>>d;
	int gcd=__gcd(w,d),lcm=w*d/gcd;
	int x=0,y=0,z=0;
	bool found=0;
	for(int i=0;i<=1e7;i++){
		int lft=p-i*d;
		if(lft%w==0&&lft>=0){
			x+=lft/w;y+=i;
			found=1;
			break;
		}
	}
	if(!found)puts("-1"),exit(0);
	if(x+y>n)puts("-1"),exit(0);
	cout<<x<<" "<<y<<" "<<n-x-y<<endl;
	return 0;
}