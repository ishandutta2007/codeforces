#include"bits/stdc++.h"
using namespace std;
int n,s,k;int nn;
double p[100005]={0};

int main()
{
    p[1]=1;
    for(int i=2;i<100005;i++)p[i]=p[i-1]+1.0/i;
    cin>>n;
    printf("%lf",p[n]);
    return 0;
}