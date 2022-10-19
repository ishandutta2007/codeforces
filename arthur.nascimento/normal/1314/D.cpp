#include <bits/stdc++.h>
#define maxn 88
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;


int ans;
int M[maxn][maxn];
int n,k;

vector<pii> opt[maxn][maxn];

int dis[5][5];

int mrk[maxn];

vector<int> vx;

int dp[6][6];

void go(int pos,int foi){
    
    if(foi > k/2) return;
    if(pos == n){
       
        for(int i=0;i<foi;i++)
            for(int j=0;j<foi;j++){
                dis[i][j] = 1.02e9;
                for(auto it : opt[vx[i]][vx[j]]){
                    if(!mrk[it.second]){
                        dis[i][j] = it.first;
                        break;
                    }
                  
                }
            }
        for(int i=1;i<5;i++)
            dp[0][i] = 1.02e9;
        for(int j=1;j<=k/2;j++)
            for(int i=0;i<foi;i++){
                dp[j][i] = 1.02e9;
                for(int m=0;m<foi;m++)
                    dp[j][i] = min(dp[j][i], dp[j-1][m] + dis[i][m]);
            }
            
        if(dp[k/2][0] < 1.01e9)
            ans = min(ans, dp[k/2][0]);
            
        return;
    }
    
    go(pos+1,foi);
    mrk[pos] = 1;
    vx.pb(pos);
    go(pos+1,foi+1);
    vx.pop_back();
    mrk[pos] = 0;
    
}

main(){
    
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&M[i][j]);
            
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            vector<pii> &u = opt[i][j];
            for(int k=0;k<n;k++)
                if(k != i && k != j)
                    u.pb(pii(M[i][k]+M[k][j],k));
            sort(u.begin(), u.end());
        }
    
    ans = 1.1e9;
    vx.pb(0);
    go(1,1);
    printf("%d\n",ans);
}