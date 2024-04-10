#include <iostream>
#include <map>

#define long long long
#define M 100100

using namespace std;

long n,k,b,s[M],ans=0,a[M];
map<long, long> m;

long dop(long y){
    long f=y-b;
    f%=k;
    if (f<0)
    f+=k;
    return f;
}

long zero(void){
    long t=0,z=0;
    for (long i=1; i<=n; ++i){
        if (a[i]==0)
        ++t;
        else{
            z=z+t*(t+1)/2;
            t=0;
        }
    }
    z=z+t*(t+1)/2;
    return z;
}


int main()
{
    s[0]=0;
    cin>>k>>b>>n;

    for (long i=1; i<=n; ++i)
    cin>>a[i];

    if (b==0){
        cout<<zero();
        return 0;
    }

    k--;
    m[0]++;




    for (long i=1; i<=n; ++i){
        s[i]=s[i-1]+a[i];
        s[i]%=k;
        ans+=m[dop(s[i])];
        m[s[i]]++;
    }

    if (b!=k)
    cout<<ans;
    else
    cout<<ans-zero();

    return 0;
}