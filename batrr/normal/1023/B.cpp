#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

int main(){
    #ifdef LOCAL
    //    freopen ("test.in", "r", stdin);
    #endif
    ll n,k,l,r;
    cin>>n>>k;
    l=k/2+1,r=k-1;
    cout<<min(r,n)-min(n,l-1);                                   
}