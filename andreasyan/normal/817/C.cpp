#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;

long long n,s;

bool stg(long long x)
{
    long long xx=x;
    long long sum=0;
    while(xx)
    {
        sum+=(xx%10);
        xx/=10;
    }
    return (x-sum>=s);
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
        {
            return (n-i+1);
        }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("circles.in","r",stdin);
    //freopen("circles.out","w",stdout);
    cin>>n>>s;
    cout<<byn()<<endl;
    return 0;
}