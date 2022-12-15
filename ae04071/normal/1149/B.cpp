#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pci = pair<char,int>;

int n,m[3],q;
char s[100100],t[3][252];
int near[26][100010],lst[26],dp[251][251][251];

void upd(int ty) {
    for(int i=(ty==0 ? m[0] : 0);i<=m[0];i++) for(int j=(ty==1 ? m[1] : 0);j<=m[1];j++) for(int k=(ty==2 ? m[2] : 0);k<=m[2];k++) {
        dp[i][j][k] = n+1;
        if(i) dp[i][j][k] = min(dp[i][j][k], near[t[0][i]-'a'][dp[i-1][j][k]]+1);
        if(j) dp[i][j][k] = min(dp[i][j][k], near[t[1][j]-'a'][dp[i][j-1][k]]+1);
        if(k) dp[i][j][k] = min(dp[i][j][k], near[t[2][k]-'a'][dp[i][j][k-1]]+1);
    }
}
int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",s);

    for(int i=0;i<26;i++) lst[i]=n;
    for(int i=0;i<=n+1;i++)for(int j=0;j<26;j++) near[j][i]=n;
    for(int i=n-1;i>=0;i--) {
        lst[s[i]-'a'] = i;
        for(int j=0;j<26;j++) near[j][i] = lst[j];
    }
    dp[0][0][0]=0;
    
    while(q--){
        char ty,ch;
        int v;
        scanf(" %c %d",&ty,&v);
        v--; 
        if(ty=='+') {
            scanf(" %c",&ch);
            t[v][++m[v]] = ch;
            upd(v);
        }
        else m[v]--;
        
        puts(dp[m[0]][m[1]][m[2]] <= n ? "YES" : "NO");
    }
    return 0;
}