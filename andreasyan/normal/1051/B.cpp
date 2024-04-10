#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1000006;

long long gcd(long long x,long long y)
{
    if(x==0)
        return y;
    return gcd(y%x,x);
}

int main()
{
    //freopen("input.txt","r",stdin);
    long long l,r;
    cin>>l>>r;
    cout<<"YES"<<endl;
    for(long long i=l;i<=r;i+=2)
        cout<<i<<' '<<i+1<<endl;
    return 0;
}