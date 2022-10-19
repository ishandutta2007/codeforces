#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

vector<long long> v;
void pre()
{
    for(int i=0;i<=12;++i)
    {
        for(long long j=0;j<=9;++j)
        {
            long long x=j;
            for(int k=0;k<i;++k)
            {
                x*=10;
                x+=9;
            }
            v.push_back(x);
        }
    }
}

long long n;

long long S(long long x)
{
    long long ans=0;
    while(x)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

long long solv1(long long n)
{
    long long maxu=0,maxi;
    for(long long a=0;a<=n;++a)
    {
        if(S(a)+S(n-a)>maxu)
        {
            maxu=S(a)+S(n-a);
            maxi=a;
        }
    }
    return maxi;
}

long long solv2(long long n)
{
    long long maxu=0,maxi;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]<=n)
        {
            if(S(v[i])+S(n-v[i])>maxu)
            {
                maxu=S(v[i])+S(n-v[i]);
                maxi=v[i];
            }
        }
    }
    return maxi;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    pre();
    long long a=solv2(n);
    long long b=n-a;
    cout<<S(a)+S(b)<<endl;
    return 0;
}