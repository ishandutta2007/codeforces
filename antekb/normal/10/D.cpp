#include<bits/stdc++.h>
using namespace std;
const int N=505;
int A[N], B[N];
int dp[N][N], tab[N][N];
int main(){
    int n, m;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        cin>>B[i];
    }
    A[0]=-1;
    B[0]=-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            tab[i][j]=tab[i-1][j];
            dp[i][j]=dp[i-1][j];
            if(A[i]==B[j]){
                int x=0;
                for(int k=0; k<j; k++){
                    if(B[j]>B[k] and dp[i-1][k]+1>x){
                        x=dp[i-1][k]+1;
                        tab[i][j]=k;
                    }
                }
                if(dp[i][j]<x){
                    dp[i][j]=x;
                }
            }
        }
    }
    int ans=-1, wsk=-1;
    for(int i=1; i<=m; i++){
        if(dp[n][i]>ans){
            ans=dp[n][i];
            wsk=i;
        }
    }
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<ans<<"\n";
    if(ans==0)  return 0;
    vector<int> V;
    int id=n;
    while(wsk!=0){
        while(A[id]!=B[wsk] and id!=0){
            id--;
        }
        V.push_back(B[wsk]);
        wsk=tab[id][wsk];
        id--;
    }
    reverse(V.begin(), V.end());
    for(int i:V){
        cout<<i<<" ";
    }
}