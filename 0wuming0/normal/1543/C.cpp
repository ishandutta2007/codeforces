#include"bits/stdc++.h"
using namespace std;
#define ll long long
double v;
double solve2(double c,double p)
{
    double ans=p;
    if(c>1e-9)
    {
        ans+=c+c*solve2(c-min(c,v),p+min(c,v));
    }
    else return 1;
    return ans;
}
double solve(double c,double m,double p)
{
    double ans=p;
    if(c<=1e-9)return solve2(m,p);
    if(m<=1e-9)return solve2(c,p);
    if(c>1e-9)
    {
        ans+=c+c*solve(c-min(c,v),m+0.5*min(c,v),p+0.5*min(c,v));
    }
    if(m>1e-9)
    {
        ans+=m+m*solve(c+0.5*min(m,v),m-min(m,v),p+0.5*min(m,v));
    }
    return ans;
}

double c,m,p;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>c>>m>>p>>v;
        printf("%.9f\n",solve(c,m,p));
    }
    return 0;
}