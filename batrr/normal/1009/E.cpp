#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=1e6+123,inf=1e18,mod=998244353;

ll n,a[maxn],p2[maxn],ans;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    p2[0]=1;
    for(int i=1;i<=n;i++)
        p2[i]=p2[i-1]*2%mod;
    for(int i=1;i<=n;i++){
        ans=(ans+a[i]*p2[n-i])%mod;
        if(n!=i)
            ans=(ans+a[i]*p2[n-i-1]%mod*(n-i)%mod)%mod;
    }
    cout<<(ans%mod+mod)%mod;

}