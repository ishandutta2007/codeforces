#include"bits/stdc++.h"
using namespace std;
#define gcd __gcd
long long fun(long long x)
{
    long long ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main()
{
    long long n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long long i=n;;i++)
        {
            if(gcd(fun(i),i)>1)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}