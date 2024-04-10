#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>m>>n;
    double ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=pow((double)i/m,n);
    }
    printf("%lf",m-ans+1);
    return 0;
}