#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

long long hcf1(long long a,long long b)
{
    if(a==0)
	{
		return b;
	}
	else
	{
		return hcf1(b%a,a);
	}
	return 0;

}
int main() 
{
    long long t,w,b;
    cin>>t>>w>>b;
    long long to=t;
    long long hcf=hcf1(w,b);
    long long lcm=(w/hcf)*b;
    bool check=false;
    if(lcm/b==w/hcf)
    {
        check=true;
    }
    long long ans1=0;
    if(check==true)
    {
        long long k=1;
        k=t/lcm;
        ans1=(min(w,b))*k;
        t=t-lcm*k;
    }
    long long ans2=min(min(w,b)-1,t);
    long long gcd=hcf1(ans1+ans2,to);
    cout<<(ans1+ans2)/gcd<<"/"<<to/gcd;
    return 0;
}