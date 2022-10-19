#include<bits/stdc++.h>
using namespace std;
const int N=80, T=10000, INF=1e9+5;
int c[N], dp[15][N], e[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(23524636);
    int n, k;
    cin>>n>>k;

    for(int  i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>e[i][j];
        }
    }
    int wynik=INF;
    for(int t=0; t<T; t++){
        vector<int> r, b;
        for(int i=0; i<n; i++){
            c[i]=rand()%2;
            if(c[i]){
                r.push_back(i);
            }
            else{
                b.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            for(int l=0; l<=k; l++){
                dp[l][i]=INF;
            }
        }
        dp[0][0]=0;
        for(int l=1; l<=k; l++){
            for(int i=0; i<n; i++){
                //cout<<c[i]<<" ";
                if(c[i]){
                    for(int j:b){
                        if(dp[l-1][j]!=INF){
                            dp[l][i]=min(dp[l][i], e[j][i]+dp[l-1][j]);
                        }
                    }
                }
                else{
                    for(int j:r){
                        if(dp[l-1][j]!=INF){
                            dp[l][i]=min(dp[l][i], e[j][i]+dp[l-1][j]);
                        }
                    }
                }
                //cout<<dp[l][i]<<" ";
            }
            //cout<<"\n";
        }
        //cout<<"\n"
        wynik=min(wynik, dp[k][0]);
    }
    cout<<wynik;
}