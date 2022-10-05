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

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;
ll n,k;
ll binpow(ll n,ll p){
    ll res=1;
    while(p){
        if(p&1)
            res=res*n%mod;
        n=n*n%mod;
        p/=2;
    }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>k;
    if(n==0)
        cout<<0;
    else
        cout<<(binpow(2,k)*(2*n%mod-1+mod)%mod+1)%mod;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}