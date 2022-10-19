#include<bits/stdc++.h>
using namespace std;
const int N=105;
int dp[N][N], ile[N][N], pocz[N][N], kon[N][N];
int tab[N];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        for(int j=1; j<=k; j++){
            int l, r;
            cin>>l>>r;
            pocz[i][j]=l;
            kon[i][j]=r;
            for(int id=l; id<=r; id++)ile[i][id]=j;
        }
        pocz[i][k+1]=m+1;
        ile[i][m+1]=k+1;
    }
    for(int d=0; d<m; d++){
        for(int i=1; i+d<=m; i++){
            for(int j=0; j<n; j++){
                if(ile[j][i-1]+1<ile[j][i+d+1]){
                    tab[kon[j][ile[j][i-1]]+1]++;
                    tab[pocz[j][ile[j][i+d+1]]]--;
                }
            }
            int cnt=0;
            for(int j=i; j<=i+d; j++){
                cnt+=tab[j];
                dp[i][i+d]=max(dp[i][i+d], dp[i][j-1]+dp[j+1][i+d]+cnt*cnt);
            }
            for(int j=i-1; j<=i+d+1; j++){
                tab[j]=0;
            }
            //cout<<i<<" "<<i+d<<" "<<cnt<<"\n";
        }
    }
    cout<<dp[1][m];
}