#include <bits/stdc++.h>
using namespace std;
long long n,q,lastdel[4000000],last,v[10000000],type,x;
vector <long long > masseges;
void pluss(long long i,long long l,long long r,long long x)
{
    if (x<l || x>r) return; else
        if (l==r)
        {
            v[i]++;
            return;
        }
    long long d=(l+r)/2;
    pluss(i*2,l,d,x);
    pluss(i*2+1,d+1,r,x);
    v[i]=v[i*2]+v[i*2+1];
}
void makenul(long long i,long long l,long long r,long long x)
{
    if (x<l || x>r) return; else
    if (l==r)
        {
            v[i]=0;
            return;
        }
    long long d=(l+r)/2;
    makenul(i*2,l,d,x);
    makenul(i*2+1,d+1,r,x);
    v[i]=v[i*2]+v[i*2+1];
}
void minuss(long long i,long long l,long long r,long long x)
{
    //cout<<x<<'!';
    if (x<l || x>r) return; else
        if (l==r)
        {
            v[i]--;
            return;
        }
    long long d=(l+r)/2;
    minuss(i*2,l,d,x);
    minuss(i*2+1,d+1,r,x);
    v[i]=v[i*2]+v[i*2+1];
}
int main()
{
    cin>>n>>q;

    for (int i=1;i<=n;i++) lastdel[i]=-1;
    while (q--)
    {
        cin>>type>>x;
        if (type==1)
        {
            pluss(1,1,n+10,x);
            masseges.push_back(x);
        } else
        if (type==2)
        {
            makenul(1,1,n+10,x);
            if (!masseges.empty())
            lastdel[x]=masseges.size();
        } else
        if (type==3)
        {
            //cout<<masseges.size()<<' '<<x<<' '<<last<<'\n';
            for (int i=last;i<x;i++)
                    if (lastdel[masseges[i]]<=i)
                    minuss(1,1,n+10,masseges[i]);
            last=max(last,x);
        }
        cout<<v[1]<<'\n';
    }
}