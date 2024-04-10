#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

vector<pair<long long,int>> v;
vector<long long> d;

void gen(int idx,long long now)
{
    if(idx==(int)v.size()) d.push_back(now);
    else
    {
        for(int i=0;i<=v[idx].second;i++)
        {
            gen(idx+1,now);
            now*=v[idx].first;
        }
    }
}

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
    long long x;
    scanf("%I64d",&x);
    long long t=x;
    for(long long i=2;i*i<=t;i++)
    {
        if((t%i)==0) v.push_back({i,0});
        while((t%i)==0)
        {
            v.back().second++;
            t/=i;
        }
    }
    if(t>1) v.push_back({t,1});
    gen(0,1);
    int m=d.size();
    long long a=1,b=x;
    for(int i=0;i<m;i++)
    {
        if(gcd(d[i],x/d[i])==1&&max(d[i],x/d[i])<max(a,b)) tie(a,b)=make_pair(d[i],x/d[i]);
    }
    printf("%I64d %I64d\n",a,b);
    return 0;
}