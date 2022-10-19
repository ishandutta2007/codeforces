#include <bits/stdc++.h>
#define maxn 202
#define pb push_back
#define ll long long
#define debug
#define mk make_pair
#define pii pair<int,int>
using namespace std;

int ans[maxn];

int qtd[maxn][26];

vector<int> val[maxn];

vector<pair<int,vector<int > > > L[maxn];

char str[maxn];
int cur[26];

int n;
void go(int a,int b){
    if(a > b) return;
    printf("? %d %d\n",a+1,b+1);
    fflush(stdout);
    for(int i=0;i<=n;i++){
        val[i].clear();
        for(int j=0;j<26;j++)
            qtd[i][j] = 0;
    }
    
    int m = b-a+1;
    int S = (m*m+m)/2;
    for(int i=0;i<S;i++){
        scanf(" %s",str);
        int sz = strlen(str);
        for(int j=0;j<sz;j++)
            qtd[sz][str[j]-'a']++;
    }
    
    for(int t=2;t<=(m+3)/2;t++){
        for(int i=0;i<26;i++)
            cur[i] = t*qtd[1][i] - qtd[t][i];
        for(int i=t-3,j=2;i>=0;i--,j++){
            cur[val[i][0]] -= j;
            cur[val[i][1]] -= j;
        }
        for(int i=0;i<26;i++)
            while(cur[i] > 0){
                val[t-2].pb(i);
                cur[i]--;
            }
                
        debug("val %d: ",t-2);for(int i=0;i<val[t-2].size();i++)debug("%d ",val[t-2][i]); debug("\n");
                
        L[a+t-2].pb(mk(b+1-t+1,val[t-2]));
        L[b+1-t+1].pb(mk(a+t-2,val[t-2]));
        debug("%d -> %d : %c %c\n",a+t-2,b+1-t+1,val[t-2][0]+'a',val[t-2][1]+'a');
        if(a+t-2 == b+1-t+1) ans[a+t-2] = val[t-2][0];
    
    }
    
}

void dfs(int v){  ;
    for(int i=0;i<L[v].size();i++){
        int to = L[v][i].first;
        vector<int> t = L[v][i].second;
        if(ans[to]+1) continue;
        ans[to] = t[0];
        if(ans[v] == t[0]) ans[to] = t[1];
        dfs(to);
    }
}

int main() {
    memset(ans,-1,sizeof(ans));
    scanf("%d",&n);
    go(0,n-1);
    go(0,n/2-1);
  
  if(n%2 == 1)  go(n/2,n-1);
  else go(n/2-1,n-1);
    for(int i=0;i<n;i++)
        if(ans[i] >= 0)
            dfs(i);
    printf("! ");
    for(int i=0;i<n;i++)
        printf("%c",ans[i]+'a');
    printf("\n");
    
}