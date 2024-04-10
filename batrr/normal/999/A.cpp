#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1e6+123,LOG=18,inf=1e9,block=450,N=1e7;
const ll INF=1e18;

int n,k,a[maxn],was[maxn],ans;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif  
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]<=k)
            was[i]=1;
         else
            break;
    for(int i=n;i>=1;i--)
        if(a[i]<=k)
            was[i]=1;
         else
            break;
    for(int i=1;i<=n;i++)
        if(was[i])
            ans++;
    cout<<ans;
}