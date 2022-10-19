#include <iostream>
#include <algorithm>

#define long long long
#define M 100100

using namespace std;

long n,f[M][2],a[M],b[M],l=0,r=1,k,s=0,ans=0;

void inc(long x,long v,long h){
    for (long i=x; i<=n; i=(i|(i+1)))
    f[i][h]+=v;
}

long get(long x,long h){
    long s=0;
    for (long i=x; i>=0; i=(i&(i+1))-1)
    s+=f[i][h];
    return s;
}

long sum(long l,long r,long h){
    if(l>r)
    return 0;
    return get(r,h)-get(l-1,h);
}

void read(void){
    cin>>n>>k;
    for (long i=0; i<n; ++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
}

long num(long a){
    return (long)(lower_bound(b,b+n,a)-b);
}

void push(long t){
    s=s+sum(t+1,n,0)+sum(0,t-1,1);
    inc(t,1,0);
}

void del(long t){
    s=s-sum(t+1,n,0)-sum(0,t-1,1);
    inc(t,-1,1);
}

void pre(void){
    push(num(a[0]));
    for (long i=n-1,t; i>0; --i){
        t=num(a[i]);
        s=s+sum(t+1,n,0)+sum(0,t-1,1);
        inc(t,1,1);
    }
}

void doit(void){
    while (r<n && l+1<n){
        while (r<n && s>k)
        del(num(a[r++]));
        if (s<=k)
        ans=ans+n-r;
        push(num(a[++l]));
        if (l==r)
        del(num(a[r++]));
    }
    cout<<ans;
}

int main()
{
    read();
    pre();
    doit();
    return 0;
}