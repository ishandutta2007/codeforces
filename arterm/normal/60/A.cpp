#include <iostream>
#include <string>

using namespace std;

long n,m;
bool u[1299];
string s,t;

void read(void){
    cin>>n>>m;
}

void solve(void){
    long x;
    for (long i=0; i<m; ++i){
        cin>>s;
        cin>>s;
        cin>>t;
        cin>>s;
        cin>>x;
        if (t=="left")
        for (long j=x; j<=n; ++j)
        u[j]=1;
        else
        for (long j=1; j<=x; ++j)
        u[j]=1;
    }
    long ans=0;
    for (long i=1; i<=n; ++i)
    if (!u[i])
    ans++;
    if (ans==0)
    ans=-1;
    cout<<ans<<"\n";
}

int main(){
    read();
    solve();
    return 0;
}