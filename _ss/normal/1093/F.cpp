#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1,mod=998244353;
queue<ll> p[101];
ll a[maxn],n,k,len,s[101],d[101],sum;

void read()
{
    cin>>n>>k>>len;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void clearqueue(int i)
{
    while (!p[i].empty()) p[i].pop();
}

bool check()
{
    int h=1;
    for (int i=1;i<n;i++)
        if (a[i]!=a[i+1] || a[i+1]==-1 || a[i]==-1)
        {
            if (h>=len) return false;
            h=1;
        }
        else h++;
    return (h<len);
}

void process()
{
    if (a[1]==-1)
    {
        for (int i=1;i<=k;i++) p[i].push(1),s[i]=1;
        sum=k;
    }
    else
    {
        p[a[1]].push(1);
        s[a[1]]=1;
        sum=1;
    }
    for (int i=2;i<=n;i++)
        if (a[i]==-1)
        {
            for (int j=1;j<=k;j++) d[j]=(sum-s[j]+mod)%mod;
            for (int j=1;j<=k;j++)
            {
                p[j].push(d[j]);
                s[j]=(s[j]+d[j])%mod;
                sum=(sum+d[j])%mod;
                if (p[j].size()>=len)
                {
                    s[j]=(s[j]-p[j].front()+mod)%mod;
                    sum=(sum-p[j].front()+mod)%mod;
                    p[j].pop();
                }
            }
        }
        else
        {
            d[a[i]]=(sum-s[a[i]]+mod)%mod;
            p[a[i]].push(d[a[i]]);
            s[a[i]]=(s[a[i]]+d[a[i]])%mod;
            if (p[a[i]].size()>=len)
            {
                s[a[i]]=(s[a[i]]-p[a[i]].front()+mod)%mod;
                p[a[i]].pop();
            }
            for (int j=1;j<=k;j++)
                if (j!=a[i]) clearqueue(j),s[j]=0;
            sum=s[a[i]];
        }
    if (check()) cout<<sum; else cout<<0;
}

int main()
{
    read();
    process();
    return 0;
}