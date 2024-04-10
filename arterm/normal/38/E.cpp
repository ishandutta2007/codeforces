#include <iostream>
#include <algorithm>

#define M 3030
#define f first
#define s second
#define mp make_pair
#define long long long

using namespace std;

long n,c[M],x[M],d[M];
pair<long,long> f[M];

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>f[i].f>>f[i].s;
    sort(f,f+n);
    for (long i=0; i<n; ++i){
        x[i]=f[i].f;
        c[i]=f[i].s;
    }
}

void din(void){
    long s;
    d[n]=0;
    for (long i=n-1; i>=0; --i){
        s=0;
        d[i]=c[i]+d[i+1];
        for (long j=i+1; j<=n; ++j){
            d[i]=min(d[i],(c[i]+s+d[j]));
            s+=(x[j]-x[i]);
        }
    }
    cout<<d[0];
}

int main()
{
    read();
    din();
    return 0;
}