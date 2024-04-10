#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
ll n,a[maxn],ans;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif        
    cin>>n;
    for(int i=0;i<n+n;i++)
        cin>>a[i];
    sort(a,a+n+n);
    ans=(a[2*n-1]-a[n])*(a[n-1]-a[0]);
    for(int i=1;i<n;i++)
        ans=min(ans,(a[n+n-1]-a[0])*(a[i+n-1]-a[i]));
    cout<<ans;
}