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
ll n,a[maxn],ans;
map<ll,ll>was;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        was[a[i]]++;
    }
    for(int i=0;i<n;i++){
        bool ok=0;
        was[a[i]]--;
        for(int j=0;j<31;j++){
            if( was[(1ll<<j)-a[i]] ){
            //    cout<<a[i]<<" "<<(1ll<<j)<<endl;
                ok=1;
            }
        }
        was[a[i]]++;
        if(ok==0)
            ans++;
    }
    cout<<ans;

}