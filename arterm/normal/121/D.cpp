#include <iostream>

#define long long long
#define L 524286
#define M 100100
#define INF 1000111000000000000LL

using namespace std;

long a[L+100],l[M],r[M],ml=INF,n,k;

bool che(long lg, long rg){
    long ans=0;
    for (long i=0; i<n; ++i){
        if (lg<l[i])
        ans+=(l[i]-lg);
        if (r[i]<rg)
        ans+=(rg-r[i]);
        if (ans>k)
        return 0;
    }
    return 1;
}

long bin(void){
    bool fl=0;
    long le=0,re=L,m;
    while (le<re){
        fl=0;
        m=(le+re+2)/2;
        for (long j=0; j+m<=L && !fl; ++j)
        if (a[j+m]-a[j+1]<=ml)
        fl=che(a[j+1],a[j+m]);

        fl ? le=m:re=m-1;
    }
    return le;
}

void read(void){
    cin>>n>>k;
    for (long i=0; i<n; ++i){
        cin>>l[i]>>r[i];
        ml=min(ml,(r[i]-l[i]));
    }
}

long luck(long t){
    long a=0,d=1<<20;
    while (d>0){
        if (t>=2*d)
        if (t&d)
        a=10*a+7;
        else
        a=10*a+4;
        d>>=1;
    }
    return a;
}

void pre(void){
    for (long i=2; i<L+10; ++i)
    a[i-1]=luck(i);
}

int main()
{
    pre();
    read();
    cout<<bin();
    return 0;
}