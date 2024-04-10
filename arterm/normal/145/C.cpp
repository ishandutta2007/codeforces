#include <iostream>

#define M 1111
#define p 1000000007
#define long long long

using namespace std;

long n,k,t=0, a[M], d[M][M], u=1, c[M];

long lucky(long x){
    long a=1;
    for (;x>0;x/=10){
        if (!(x%10==4 || x%10==7))
        return 0;
        if (x%10==4)
        a=2*a;
        else
        a=2*a+1;
    }
    return a;
}

long pow(long a, long x){
    long b=a,u=1,ans=1;
    while (u<=x){
        if (u&x)
        ans=(ans*b)%p;
        b=(b*b)%p;
        u<<=1;
    }
    return ans;
}



void read(void){
    long b,l;
    cin>>n>>k;
    for (long i=0; i<M; ++i)
    a[i]=0;
    for (long i=0; i<n; ++i){
        cin>>b;
        l=lucky(b);
        if (l!=0){
            u=max(u,l);
            a[l]++;
        }
        else
        t++;
    }
}

void din(void){
    for (long i=0; i<M; ++i)
    for (long j=0; j<M; ++j)
    d[i][j]=0;

    d[1][1]=a[1];
    for (long i=1; i<=u; ++i)
    d[i][0]=1;
    for (long i=2; i<=u; ++i)
    for (long j=1; j<M; ++j)
    d[i][j]=(d[i-1][j]+d[i-1][j-1]*a[i])%p;
}

void calcc(void){
    long d=1;
    c[0]=1;
    for (long i=0; i<k; ++i)
    c[0]=(c[0]*(t-i))%p;
    for (long i=1; i<=k; ++i)
    c[0]=(c[0]*pow(i,p-2))%p;

    while(k-d>t){
        c[d]=0;
        ++d;
    }
    if (k-d==t){
        c[d]=1;
        d++;
    }
    for (;d<M; ++d)
    c[d]=(((c[d-1]*(k+1-d))%p)*pow(t+d-k,p-2))%p;

}

long fin(void){
    long ans=0;
    if (t==0)
    ans=d[u][k];
    else
    for (long i=0; i<=k; ++i)
    ans=(ans+d[u][i]*c[i])%p;
    return ans;
}
int main()
{
    read();
    din();
    calcc();
    //cout<<t<<"\n";
    //cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" ";
    cout<<fin();
    return 0;
}