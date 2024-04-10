#include<bits/stdc++.h>
using namespace std;
double x[100010],y[100010];
int N;
bool check(long double k)
{
    long double l=-100000000000000000.0,r=100000000000000000.0,t;
    for(int i=1;i<=N;i++)
    {
        if(y[i]>k*2)
            return 0;
        t=sqrt(k*k-(k-y[i])*(k-(y[i])));//
        if(l < x[i]-t) l = x[i]-t;
        if(r > x[i]+t) r = x[i]+t;
    }
    return l<r;//
}
int main()
{
 
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%lf %lf",&x[i],&y[i]);
    for(int i=1;i<=N;i++)
        if(y[i]*y[N]<0)
        {
            puts("-1");
            return 0;
        }
        else y[i]=y[i]>0?y[i]:-y[i];//
 
    long double l=0,r=100000000000000000.0,m;
    for(int i=1;i<=100;i++)//
    {
        m=(l+r)/2.0;
        if(check(m))
            r=m;
        else
            l=m;
    }
    printf("%.10Lf",m);
    return 0;
}