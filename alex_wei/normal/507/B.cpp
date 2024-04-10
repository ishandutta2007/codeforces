#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
int r,x,y,x1,y1;
int main(){
	cin>>r>>x>>y>>x1>>y1;
	double dis=sqrt(1ll*(x-x1)*(x-x1)+1ll*(y-y1)*(y-y1));
	int ans=dis/r/2;
	if(abs(dis-ans*r*2)>1e-8)ans++;
	cout<<ans;
    return 0;
}