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
ll n,x,cnt[10],ans;
double sum,need;
int main(){
    #ifdef LOCAL
    //    freopen ("test.in", "r", stdin);
    #endif        
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cnt[x]++;
        sum+=x;
    }
    need=4.5*n;    
    while( cnt[2]>0 && sum<need ){
        cnt[2]--;
        sum=sum-2+5;
        ans++;    
    }
               
    while( cnt[3]>0 && sum<need ){
        cnt[3]--;
        sum=sum-3+5;
        ans++;    
    }
               
    while( cnt[4]>0 && sum<need ){
        cnt[4]--;
        sum=sum-4+5;
        ans++;    
    }
    cout<<ans;
}