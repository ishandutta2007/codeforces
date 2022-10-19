#include <iostream>

#define M 100101
#define INF 1<<30;

using namespace std;

long t[4*M], m[4*M],h[M], n, k, c[M];

void mt(long l, long r, long v){
    if (l==r){
        t[v]=h[l];
        m[v]=h[l];
    }
    else{
        mt(l,(l+r)>>1,v<<1);
        mt((l+r+2)>>1,r,v<<1|1);
        t[v]=max(t[v<<1],t[v<<1|1]);
        m[v]=min(m[v<<1],m[v<<1|1]);
    }
}

long getmax(long l, long r, long lg, long rg, long v){
    if (l>rg || r<lg)
    return -INF;
    if (lg==l && rg==r)
    return t[v];
    long s=(lg+rg)>>1;
    return max( getmax(l,min(r,s),lg,s,v<<1), getmax(max(l,(s+1)),r,s+1,rg,v<<1|1));
}

long getmin(long l, long r, long lg, long rg, long v){
    if (l>rg || r<lg)
    return INF;
    if (lg==l && rg==r)
    return m[v];
    long s=(lg+rg)/2;
    return min( getmin(l,min(r,s),lg,s,v<<1), getmin(max(l,(s+1)),r,s+1,rg,v<<1|1));
}

long del(long l, long r){
    return getmax(l,r,1,n,1)-getmin(l,r,1,n,1);
}

void read(void){
    long l=1,r=1,ans=0,b=0;
    cin>>n>>k;
    for (long i=1; i<=n; ++i)
    cin>>h[i];
    mt(1,n,1);
    while (r<n){
        while (del(l,r)<=k && r<n)
        r++;
        while (del(l,r)>k){
            c[l]=r-l;
            ans=max(ans,c[l]);
            l++;
        }
    }
    while (l<=n){
        c[l]=n+1-l;
        ans=max(ans,c[l]);
        l++;
    }
    for (long i=1; i<=n; ++i)
    if (c[i]==ans)
    b++;
    cout<<ans<<" "<<b<<"\n";
    for (long i=1; i<=n; ++i)
    if (c[i]==ans)
    cout<<i<<" "<<i+ans-1<<"\n";
}



int main()
{
    read();
    return 0;
}