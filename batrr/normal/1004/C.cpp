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
ll n,ans,a[maxn],cnt1[maxn],cnt2[maxn],CNT;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(cnt1[a[i]]==0)
            CNT++;
        cnt1[a[i]]++;
    }
    
    for(int i=0;i<n;i++){
        cnt2[a[i]]++;
        if(cnt2[a[i]]==cnt1[a[i]])
            CNT--;
        if(cnt2[a[i]]==1)
            ans+=CNT;    
    }
    cout<<ans;
}