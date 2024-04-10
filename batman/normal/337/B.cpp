#include <bits/stdc++.h>
using namespace std;



int main()
{ 
    int a,b,c,d,x1,x2,y1,y2;
    cin>>a>>b>>c>>d;
    x1 = b*c;
    y1 = b*c - a*d;
    x2 = a*d;
    y2 = a*d - b*c;
    if(y1>=0)
    {
        int ex=__gcd(x1,y1);
        x1/=ex;
        y1/=ex;
        cout<<min(x1,y1)<<"/"<<max(x1,y1);
    }
    else
    {
        int ex=__gcd(x2,y2);
        x2/=ex;
        y2/=ex;
        cout<<min(x2,y2)<<"/"<<max(x2,y2);
    }
    return 0;
}