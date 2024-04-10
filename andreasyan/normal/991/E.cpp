#include <bits/stdc++.h>
using namespace std;
const int N=10;

long long ans;

long long n;

int a[N];

long long f[N+N];
void pre()
{
    f[0]=1;
    for(int i=1;i<=18;++i)
        f[i]=f[i-1]*i;
}

long long zug(int nn,int k)
{
    return f[nn]/(f[nn-k]*f[k]);
}

int b[N];

void ave()
{
    int x=0;
    for(int i=1;i<N;++i)
    {
        x+=b[i];
    }
    long long res=f[x];
    for(int i=1;i<N;++i)
    {
        res/=f[b[i]];
    }
    res=res*zug(x+b[0]-1,b[0]);
    ans+=res;
}

void rec(int x)
{
    if(x==10)
    {
        ave();
        return;
    }
    if(!a[x])
    {
        b[x]=0;
        rec(x+1);
    }
    for(int i=1;i<=a[x];++i)
    {
        b[x]=i;
        rec(x+1);
    }
}

int main()
{
    pre();
    cin>>n;
    while(n)
    {
        a[n%10]++;
        n/=10;
    }
    rec(0);
    cout<<ans<<endl;
    return 0;
}