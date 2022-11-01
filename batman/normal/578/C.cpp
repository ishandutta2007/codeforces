#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define N (201*1000)
ll n;
ld a[N];

ld solve(ld x)
{
	ld all[2]={},now[2]={};
	for(int i=0;i<n;i++)
	{
		if(now[0]+((ld)a[i]-x)>0)
		{
			now[0]+=(ld)a[i]-x;
			all[0]=max(all[0],now[0]);
		}
		else
			now[0]=0;
		if(now[1]+(x-(ld)a[i])>0)
		{
			now[1]+=x-(ld)a[i];
			all[1]=max(all[1],now[1]);
		}
		else
			now[1]=0;
		//cout<<now[0]<<" "<<all[0]<<"\n";
		//cout<<now[1]<<" "<<all[1]<<"\n";	
	}
	return max(all[0],all[1]);
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    ld l=-N,r=N;
    //cout<<solve(2.5)<<endl;
    for(int i=0;i<111;i++)
    {
    	ld mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
    	if(solve(mid1)>solve(mid2))
    		l=mid1;
    	else
			r=mid2;	
		//cout<<l<<" "<<r<<endl;	
	}
	cout<<fixed<<setprecision(10)<<min(solve(l),solve(r))<<endl;
	
	
    return 0;
}