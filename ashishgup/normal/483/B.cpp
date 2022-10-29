#include <bits/stdc++.h>
#define ll long long
#define IOS sync_with_stdio(false);
using namespace std;

int main()
{
    long long c1,c2,x,y;
    cin>>c1>>c2>>x>>y;
    long long l=1;
    long long r=x*y*(c1+c2);
    long long mid=0;
    while(true)
    {
        mid=l+(r-l)/2;
        long long A=c1-mid/y+mid/(x*y);
        long long B=c2-mid/x+mid/(x*y);
        if(A<0)
        {
            A=0;
        }
        if(B<0)
        {
            B=0;
        }
        long long C=mid-mid/x-mid/y+mid/(x*y);
        if(A+B<C)
        {
            r=mid-1;
        }
        else if(A+B>C)
        {
            l=mid+1;
        }
        else
        {
            long long mid1=mid-1;
            long long A1=c1-mid1/y+mid1/(x*y);
            long long B1=c2-mid1/x+mid1/(x*y);
            long long C1=mid1-mid1/x-mid1/y+mid1/(x*y);
            if(A1+B1==C1)
            {
                cout<<mid1;
                return 0;
            }
            if(mid%(x*y)==0)
            {
                cout<<mid1;
                return 0;
            }
            cout<<mid;
            return 0;
        }
        
    }
}