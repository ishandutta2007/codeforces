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
int n,d,ans,a[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>2*d)
            ans+=2;
        if(a[i]-a[i-1]==2*d)
            ans++;
    }
    cout<<ans+2;
}