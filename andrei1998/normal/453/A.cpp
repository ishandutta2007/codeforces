#include <iostream>
#include <iomanip>

using namespace std;

long double exp(long double a,int b)
{
    if(!b)
        return 1;
    else if(b&1){
        return (a*exp(a,b-1));
    }
    else{
        long double aux=exp(a,b>>1);
        return (aux*aux);
    }
}

long double p[100005];

int main()
{
    int n,m;
    cin>>m>>n;

    for(int i=1;i<=m;i++)
        p[i]=exp((((long double)i)/m),n);

    long double ans=0;
    for(int i=1;i<=m;i++)
        ans+=((long double)i*(p[i]-p[i-1]));

    cout<<fixed<<setprecision(12)<<ans<<'\n';
    return 0;
}