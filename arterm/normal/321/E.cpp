#include <iostream>

#define M 4040
#define N 809
#define INF 1000000000

using namespace std;

int a[M][M],d[M],p[M],f[M],n,k;

void read(void){
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    cin>>a[i][j];
    
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}

int cost(int k, int n){
    return a[n][n]-a[n][k]-a[k][n]+a[k][k];
}

void pre(void){
    p[0]=INF;
    for (int i=1; i<=n; ++i)
    p[i]=cost(0,i);
}

void copy(void){
    for (int i=0; i<=n; ++i)
    p[i]=min(d[i],INF);
}

void comp(int l, int r, int le, int re){
    if (l>r)
    return;
    
    if (l==r){
        int m=min(re,l-1);
        for (int i=m; i>=le; --i)
        if (p[i]+cost(i,l)<=p[m]+cost(m,l))
        m=i;
        d[l]=p[m]+cost(m,l);
        return;
    }
    
    int m=(l+r)/2;
    int h=min(re,m-1);
    
    for (int i=re; i>=le; --i)
    if (p[i]+cost(i,m)<=p[h]+cost(h,m))
    h=i;
    
    d[m]=p[h]+cost(h,m);
    
    comp(l,m-1,le,h);
    comp(m+1,r,h,re);
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    pre();
    for (int i=1; i<k; ++i)
    comp(1,n,1,n),
    copy();
    
    cout<<p[n]/2<<"\n";
    return 0;
}