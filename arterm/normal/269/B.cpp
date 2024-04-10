#include <iostream>

#define M 5050
#define INF 100000000

using namespace std;

long n,m,s[M],d[M];

void read(void){
    cin>>n>>m;
    double x;
    for (long i=1; i<=n; ++i)
    cin>>s[i]>>x;
}

void din(void){
    long t,k;
    d[0]=0;
    s[0]=0;
    s[n+1]=INF;

    for (long i=1; i<=n+1; ++i)
    for (long j=0; j<i; ++j)
    if (s[j]<=s[i])
    d[i]=max(d[i],(d[j]+1));

    cout<<n+1-d[n+1]<<"\n";

}

int main()
{
    read();
    din();
    return 0;
}