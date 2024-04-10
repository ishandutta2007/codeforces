#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

vector<pair<long long,int>> factorise(long long a)
{
    vector<pair<long long,int>> v;
    for(long long i=2;i*i<=a;i++)
    {
        if((a%i)==0) v.push_back({i,0});
        while((a%i)==0)
        {
            v.back().second++;
            a/=i;
        }
    }
    if(a>1) v.push_back({a,1});
    return v;
}

long long cnt(long long n,long long lim,vector<long long> bad)
{
    long long res=0;
    for(int mask=0;mask<(1<<(int)bad.size());mask++)
    {
        long long m=1;
        int c=0;
        for(int i=0;i<(int)bad.size();i++)
        {
            if(mask&(1<<i))
            {
                m*=bad[i];
                c++;
            }
        }
        if(!(c&1)) res+=(lim/(n*m));
        else res-=(lim/(n*m));
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,m;
        scanf("%I64d%I64d",&a,&m);
        long long g=gcd(a,m);
        vector<pair<long long,int>> q=factorise(m);
        vector<pair<long long,int>> e=q;
        for(pair<long long,int> &p:e)
        {
            p.second=0;
            while((g%p.first)==0)
            {
                p.second++;
                g/=p.first;
            }
        }
        vector<long long> bad;
        for(int i=0;i<(int)q.size();i++)
        {
            if(q[i].second>e[i].second) bad.push_back(q[i].first);
        }
        printf("%I64d\n",cnt(gcd(a,m),a+m-1,bad)-cnt(gcd(a,m),a-1,bad));
    }
    return 0;
}