#include <bits/stdc++.h>
using namespace std;

long long n;

bool stg(long long k)
{
    long long m=n;
    long long ans=0;
    while(1)
    {
        if(m<k)
        {
            ans+=m;
            break;
        }
        else
        {
            ans+=k;
            m-=k;
        }
        m-=(m/10);
    }
    if(n%2==0)
        return ans>=(n/2);
    else
        return ans>=(n/2+1);
}

long long byn()
{
    long long l=1,r=n;
    while((r-l)>4)
    {
        long long m=(l+r)/2;
        if(stg(m))
            r=m;
        else
            l=m;
    }
    for(long long i=l;i<=r;++i)
        if(stg(i))
            return i;
}

int main()
{
    cin>>n;
    cout<<byn()<<endl;
    return 0;
}