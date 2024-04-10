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

const ll maxn=1e6+123,inf=1e18,mod=1e9+7,N=360360;
ll n,r,a[maxn],sum;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n>>r;
    for(int i=0;i<(1<<n);i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<fixed<<setprecision(20);
    cout<<1.0*sum/(1<<n)<<endl;
    while(r--){
        int pos,x;
        cin>>pos>>x;
        sum=sum-a[pos]+x;
        a[pos]=x;
        cout<<1.0*sum/(1<<n)<<endl;
    }
}