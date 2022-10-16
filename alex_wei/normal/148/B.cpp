#include<bits/stdc++.h>
using namespace std;
#define ll long long
double vp,vd,t,f,c;
int ans;
int main()
{
	cin>>vp>>vd>>t>>f>>c;
	if(vp>=vd)cout<<0,exit(0);
	double dis=vp*(t+(t*vp)/(vd-vp));
	while(dis<c)ans++,dis+=vp*(f+dis/vd)+vp*(dis+vp*(f+dis/vd))/(vd-vp);
	cout<<ans;
    return 0;
}