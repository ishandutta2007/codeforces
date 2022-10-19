#include <iostream>
#include <math.h>

#define M 100100

using namespace std;

long n,p[M],m,k,ne[M],c[M];

void add(long a, long t){
    long r=a/k,f;
    f=r*k;
    if (!f)
    f=1;
    p[a]=t;
    for (long i=a,b; i>=f; --i){
        b=i+p[i];
        c[i]=1;
        if (b<=n && b/k==r){
            ne[i]=ne[b];
            c[i]+=c[b];
        }
        else
        ne[i]=b;
    }
}

void que(long x){
    long ans=0,e;
    while (x<=n){
        ans+=c[x];
        if  (ne[x]>n)
        e=x;
        x=ne[x];
    }
    while (e+p[e]<=n)
    e+=p[e];
    cout<<e<<" "<<ans<<"\n";
}

void read(void){
    cin>>n>>m;
    k=(long)sqrt(n);
    for (long i=1; i<=n;++i)
    cin>>p[i];
    for (long i=n,a; i>0;--i){
        a=i+p[i];
        c[i]=1;
        if (a<=n && a/k==i/k){
            ne[i]=ne[a];
            c[i]+=c[a];
        }
        else
        ne[i]=a;
    }
}

int main()
{
    read();
    for (long i=0,f,a,b; i<m; ++i){
        cin>>f;
        if (!f){
            cin>>a>>b;
            add(a,b);
        }
        else{
            cin>>a;
            que(a);
        }
    }
    return 0;
}