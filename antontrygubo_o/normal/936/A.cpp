#include <bits/stdc++.h>
using namespace std;


int main()
{
long long k, d, t;
cin>>k>>d>>t;
if (d<k) d = ((k+d-1)/d)*d;
long long timer = 0;
if (d==k) {cout<<t; return 0;}
else
{
    long long c = (2*t)/(k+d);
    timer = timer + d*c;
    long long left = (2*t)%(k+d);
    long long lef = left;
    if (2*k<=lef) {cout<<timer + lef-k; return 0;}
    else 
    {
        if (lef%2==0) cout<<timer+lef/2;
        else cout<<(timer + (lef-1)/2)<<".5";
    }
}
}