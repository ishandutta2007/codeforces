#include <bits/stdc++.h>
using namespace std;
int rdn(int y, int m, int d)
{
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
long long x2,x3,x4,y2,y3,y4,kf1,kf2,ans,n,v[1000000],a[200000],q,m,k,h1,m1,h2,m2,t1,t2,tep;
vector<pair<long long ,long long> > vec;
string st,s;


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

long long getsum(long long i,long long l, long long r,long long ll,long long rr)
{
    if (l>rr || r<ll) return(0); else
    if (l>=ll && r<=rr) return(v[i]); else
    {
        long long d=(l+r)/2;
        return(getsum(i*2,l,d,ll,rr)+getsum(i*2+1,d+1,r,ll,rr));
    }
}
/// *** program *** ///
int main()
{
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            pluss(1,1,200000,a[i]);
        }
        cin>>q;
        while (q--)
        {
            cin>>m;
            cout<<(getsum(1,1,200000,1,m))<<'\n';
        }
}