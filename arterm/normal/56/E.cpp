#include <iostream>
#include <algorithm>

#define M 100100
#define f first
#define s second
#define mp make_pair
#define INF 2000000012

using namespace std;

long n, x[M], h[M], d[M], num[M], ans[M], t[4*M], o[M];
pair<long,pair<long,long> > p[M];

bool comp(long x, long y){
    return o[x]<o[y];
}

void mt(long l, long r, long v){
    if (l==r)
    t[v]=l;
    else{
        long m=(l+r)>>1;
        mt(l,m,v<<1);
        mt(m+1,r,v<<1|1);
        t[v]=max(t[v<<1],t[v<<1|1],comp);
    }
}

long get(long l, long r, long le, long ri, long v){
    if (l==le && r==ri)
    return t[v];
    if (ri<l || r<le)
    return n;
    long m=(le+ri)/2;
    return max(get(l,min(m,r),le,m,v<<1),get(max(l,m+1),r,m+1,ri,v<<1|1),comp);
}

long bin(long xi){
    long l=0, r=n-1,m;
    while(l<r){
        m=(l+r+2)/2;
        if (x[m]<=xi)
        l=m;
        else
        r=m-1;
    }
    return l;
}

void din(void){
    long b,r;
    d[n-1]=1;
    for (long i=n-2; i>=0; --i){
        b=bin(o[i]);
        r=get(i,b,0,n-1,1);
        if (r>i)
        d[i]=r-i+d[r];
        else
        d[i]=b-i+1;
    }
    for (long i=0; i<n; ++i)
    ans[num[i]]=d[i];
    for (long i=0; i<n; ++i)
    cout<<ans[i]<<" ";
}

void read(void){
    cin>>n;
    for (long i=0,hi,xi; i<n; ++i){
        cin>>xi>>hi;
        p[i]=mp(xi,mp(hi,i));
        }
    sort(p,p+n);
    for (long i=0; i<n; ++i){
        x[i]=p[i].f;
        h[i]=p[i].s.f;
        o[i]=x[i]+h[i]-1;
        num[i]=p[i].s.s;
    }
    o[n]=-INF;
    mt(0,n-1,1);
}


int main()
{
    read();
    din();
    return 0;
}