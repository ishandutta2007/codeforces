#include <bits/stdc++.h>
using namespace std;
double a,b,c,d,v,t,e,f,g,h,l=-1,r=1e9,m,p,q;
int main()
{
    cin>>a>>b>>c>>d>>v>>t>>e>>f>>g>>h;
    for(int i=0;i<500;i++)
    {
    	m=(l+r)/2;
    	p=abs(c-a-min(m,t)*e-max(0.0,m-t)*g);
    	q=abs(d-b-min(m,t)*f-max(0.0,m-t)*h);
    	if(sqrt(p*p+q*q)<=m*v)
    		r=m;
    	else
			l=m;
	}
    printf("%.10lf",r);
    return 0;
}