#include <bits/stdc++.h>
#define maxn 300300
#define debug 
#define ll long long
using namespace std;

int dp[252][252][252];
char str[maxn];
int nxt[26][maxn];

char A[3][maxn];

int ok[252][252][252];

int go(int a,int b,int c){
    
    if(ok[a][b][c]) return dp[a][b][c];
    
    int ans = maxn;
    
    if(a) ans = min(ans, nxt[ A[0][a-1]-'a'   ][ go(a-1,b,c)+1] );
    if(b) ans = min(ans, nxt[ A[1][b-1]-'a'   ][ go(a,b-1,c)+1] );
    if(c) ans = min(ans, nxt[ A[2][c-1]-'a'   ][ go(a,b,c-1)+1] );
    
    ok[a][b][c] = 1;
    return dp[a][b][c] = ans;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    scanf(" %s",str);
    for(int i=0;i<26;i++) nxt[i][n] = nxt[i][n+1] = n;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++) nxt[j][i] = nxt[j][i+1];
        nxt[str[i]-'a'][i] = i;
    }
    
    int sz[3] = {0,0,0};
    
    dp[0][0][0] = -1;
    ok[0][0][0] = 1;
    
    while(q--){
        
        char ch;
        int id;
        char add;
        scanf(" %c %d",&ch,&id); id--;
        if(ch == '+') scanf(" %c",&add);
    
        if(ch == '-'){ 
            
            if(id == 0) for(int j=0;j<=sz[1];j++) for(int k=0;k<=sz[2];k++) ok[sz[id]][j][k] = 0;
            if(id == 1) for(int j=0;j<=sz[0];j++) for(int k=0;k<=sz[2];k++) ok[j][sz[id]][k] = 0;
            if(id == 2) for(int j=0;j<=sz[0];j++) for(int k=0;k<=sz[1];k++) ok[j][k][sz[id]] = 0;
            sz[id]--;
            
        
        }
        
        else {
            A[id][sz[id]] = add;
            sz[id]++;
            
            int ans = go(sz[0],sz[1],sz[2]);
            
           
            
            dp[sz[0]][sz[1]][sz[2]] = ans;
            debug("dp = %d\n",ans);
        
        }
        
        
        if(dp[sz[0]][sz[1]][sz[2]] < n)
            printf("YES\n");
        else
            printf("NO\n");
    
    }
    
}