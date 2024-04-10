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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e9,mod=1e9+7,N=360360;
ll k,b,n,ans,cur,a[maxn];
map<ll,ll> cnt;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    //    freopen (".out", "w", stdout);
    #endif
    cin>>k>>b>>n;
    cnt[0]++;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cur=(cur+a[i])%(k-1);
        ans+=cnt[ ( cur - b%(k-1) + (k-1) )%(k-1) ];
        cnt[cur]++;
    }
    if(b==0){
        cur=0;
        ans=0;
        for(int i=0;i<n;i++)
            if(a[i]==0)
                cur++,ans+=cur;
            else
                cur=0;
    }
    if( b==k-1 ){
        cur=0;
        for(int i=0;i<n;i++)
            if(a[i]==0)
                cur++,ans-=cur;
            else
                cur=0;
    
    }

    cout<<ans;


}