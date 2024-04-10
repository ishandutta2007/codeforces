#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7;

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    ll n,m,x,sum=0,last=0;                      
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
        cout<<sum/m-last<<" ";
        last=sum/m;
    }
}