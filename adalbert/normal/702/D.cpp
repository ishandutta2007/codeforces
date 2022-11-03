#include <bits/stdc++.h>
using namespace std;
long long d,k,a,b,t,ch,v1,v2,v3,v4;
int main()
{
    cin>>d>>k>>a>>b>>t;
    ch=k*a+t;
    v1=b*d;
    if (d>k)
    v2=(d-(k))*b+k*a; else v2=1000000000000;
    v3=(d/k)*ch+(d%k)*a;
    if (d/k>0)
    v4=((d/k)-1)*ch+k*a+(d%k)*b; else v4=1000000000000;
    cout<<min(min(v1,v2),min(v3,v4));

}