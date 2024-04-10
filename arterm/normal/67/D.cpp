#include <iostream>
#include <algorithm>
#include <vector>

#define M 1010101
#define INF 1000000007

using namespace std;

vector<long> d(M,INF);
long x[M],y[M],p[M],n;

long bin(long x){
    long l=0, r=n,m;
    while (r>l){
        m=(r+l)/2;
        if (d[m]<x)
        l=m+1;
        else
        r=m;
    }
    return l;
}

int main()
{
    long a,u;
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>x[i];
    for (long i=1; i<=n; ++i){
        cin>>a;
        y[a]=i;
    }

    for (long i=1; i<=n; ++i)
    p[i]=-y[x[i]];

    d[0]=-INF;
    for (long i=1; i<=n; ++i)
    d[i]=INF;

    for (long i=1; i<=n; ++i){
        //ong j = long (upper_bound (d.begin(), d.end(), p[i]) - d.begin());
        long j=bin(p[i]);
        d[j]=p[i];
    }

    u=0;
    while(d[u]!=INF)
    ++u;
    cout<<u-1;

    return 0;
}