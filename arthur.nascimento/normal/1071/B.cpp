#include <bits/stdc++.h>
#define maxn 2020
#define pb push_back
#define debug 
#define pii pair<int,int>
#define ppi pair<pii,int>
typedef long long ll;
using namespace std;

char mat[maxn][maxn];

int ord[maxn][maxn];
int dp[maxn][maxn];
int uu[maxn][maxn];

int main(){
    
    int n,k;
    scanf("%d%d",&n,&k);
    
    for(int i=0;i<n;i++)
        scanf(" %s",mat[i]);
    
    int best = -1;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            
            dp[i][j] = 1e5;
            if(i == 0 && j == 0)
                dp[i][j] = (mat[i][j] != 'a');
            if(i)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + (mat[i][j] != 'a'));
            if(j)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (mat[i][j] != 'a'));
        
            if(dp[i][j] <= k && i+j >= best)
                best = i + j;
            
        }
        
    for(int s = 2*n-2;s>=0;s--){
        
        vector<ppi> v;
        
        for(int i=0;i<n;i++){
            int j = s - i;
            if(j < 0 || j >= n) continue;
            int u = 1e4;
            if(i+1 < n) u = min(u,ord[i+1][j]);
            if(j+1 < n) u = min(u,ord[i][j+1]);
            uu[i][j] = u;
            v.pb(ppi(pii(mat[i][j],u),i));
        }       
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            int x = v[i].second;
            int y = s - x;
            ord[x][y] = i;
        }
        
    }
    
    int rx = 0, ry = 0, q = 1e5;
    for(int i=0;i<=best;i++)
        printf("a");
    if(best == -1)
        printf("%c",mat[0][0]), best = 0;
    for(int x=0;x<n;x++){
        int y = best-x;
        if(y < 0 || y >= n) continue;
        if(dp[x][y] > k) continue;
        if(uu[x][y] < q){
            q = uu[x][y];
            rx = x, ry = y;
        }
    }
    
    while(rx + ry != 2*n-2){
        if(rx == n-1) ry++;
        else if(ry == n-1) rx++;
        else if(ord[rx+1][ry] < ord[rx][ry+1]) rx++;
        else ry++;
        printf("%c",mat[rx][ry]);
    }
    
    
}