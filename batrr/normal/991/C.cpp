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

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
ll n,k;
ll get(ll n,ll k){
    ll res=0;
    while(n){
        //cout<<n<<" "<<k<<endl;
        if( n>=k )
            n-=k,res+=k;
        else
           res+=n,n=0;
        n=n-n/10;
    }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n;
    ll l=1,r=1e18;
    while(l<=r){
        ll m=(l+r)/2;
        if( get(n,m)<1.0*n/2 )
            l=m+1;
        else
            r=m-1;
    }
    cout<<l;
}