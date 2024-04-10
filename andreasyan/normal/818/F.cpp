#include <bits/stdc++.h>
using namespace std;
const int N=1000006;

bool stg(long long n,long long m)
{
    m-=(n-1);
    if(m==0)
        return true;
    long long x=(sqrt(1+8*m)-1)/2;
    while(x*(x+1)/2<m)
        ++x;
    m+=(n-1);
    if((n-x-2)*2>=m)
        return true;
    return false;
}

long long byn(long long n)
{
    long long l=n-1,r=n*2;
    while((r-l)>4)
    {
        long long m=(l+r)/2;
        if(stg(n,m))
            l=m;
        else
            r=m;
    }
    for(long long m=r;m>=l;--m)
        if(stg(n,m))
            return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--)
    {
        long long n;
        cin>>n;
        cout<<byn(n)<<endl;
    }
    return 0;
}