#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long h1,h2,a,b;
    cin>>h1>>h2>>a>>b;
    h1+=8*a;
    if(h1<h2&&a<=b) {
        cout<<-1;
        return 0;
    }
    if(h1>=h2) {
        cout<<0;
        return 0;
    }
    long long l=0,r=100000000;
    while(l<r)
    {
        long long m=(l+r)/2;
        if(h1+m*12*(a-b)>=h2)
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}