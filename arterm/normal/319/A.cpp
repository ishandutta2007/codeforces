#include <iostream>
#include <string>

#define mod 1000000007ll
#define long long long
#define M 200

using namespace std;

long f[M],n,ans=0;
string s;

void kill(void){
    cin>>s;
    n=s.length();
    
    f[0]=1;
    for (int i=1; i<M; ++i)
    f[i]=(2*f[i-1])%mod;

    
    for (int i=0; i<n; ++i)
    if (s[i]=='1'){
        long bon=f[n-1-i]*f[n-1-i];
        bon%=mod;
        bon*=f[i];
        bon%=mod;
        ans=(ans+bon)%mod;
    }
    cout<<ans<<"\n";
}

int main()
{
    kill();
    return 0;
}