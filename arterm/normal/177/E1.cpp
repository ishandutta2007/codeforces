#include <iostream>
#include <math.h>

#define long long long
#define M 10100
#define INF 2000000000000000000LL

using namespace std;

long n,c,a[M],b[M];
bool zero=1;

void read(void){
    cin>>n>>c;
    c-=n;
    for (long i=0; i<n; ++i){
        cin>>a[i]>>b[i];
        zero&=(a[i]==0);
    }
}

long val(long a,long b, long x){
    if (c>0 && a>0)
    if (log(a)+log(x)>log(10*c)+log(b))
    return c+1;
    if (c==0)
    if (a>b || x>b)
    return c+1;
    long e1=a/b,e2=x/b,r1=a%b,r2=x%b;
    return (a*x)/b;
    //return b*e1*e2+e1*x+a*e2+(r1*r2)/b;
}

long che(long x){
    long ans=0;
    for (long i=0; i<n && ans<=c; ++i)
    ans+=val(a[i],b[i],x);
    if (ans<=c)
    return ans;
    return c+1;
}

long bin(long t){
    c=t;
    long l=1,r=INF,m;
    while (l<r){
        m=(l+r)/2;
        if (che(m)>=c)
        r=m;
        else
        l=m+1;
    }
    return r;
}

int main()
{
    read();
    if (c<0){
        cout<<0;
        return 0;
    }

    if (c==0 && zero){
        cout<<-1;
        return 0;
    }

    if (che(1)>c){
        cout<<0;
        return 0;
    }

    long t=c;

    cout<<bin(t+1)-bin(t)<<"\n";


    return 0;
}