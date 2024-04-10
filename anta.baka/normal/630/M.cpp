#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin>>x;
    x=((long long)abs(x)%360)*(x<0?-1:1);
    if(abs(x)<=45||360-abs(x)<=45)
        cout<<0;
    else {
        if(x>0)
            x=360-x;
        else
            x=abs(x);
        int best=360,cnt=0;
        for(int i=1; i<=4; i++) {
            x=(x+90)%360;
            int d=min(x,360-x);
            if(d<best)
                best=d,cnt=i;
        }
        cout<<cnt%4;
    }
    return 0;
}