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

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;
int n,k,x,cntc[maxn],cntp[maxn],ans,a[15],dp[5000][5000];
int get(int k,int m,int n){
    // dp[n][m]=max
    if( n*k<=m )
        return a[k]*n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++)
            for(int q=0;j+q<=m && q<=k;q++)
                dp[i+1][j+q]=max(dp[i+1][j+q],dp[i][j]+a[q]);
    }
    return dp[n][m];
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n>>k;
    for(int i=0;i<n*k;i++){
        cin>>x;
        cntc[x]++;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        cntp[x]++;
    }
    for(int i=1;i<=k;i++)
        cin>>a[i];
    for(int i=0;i<maxn;i++){
        if(cntp[i] && cntc[i]){
            ans+=get(k,cntc[i],cntp[i]);
        }
    }        
    cout<<ans;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}