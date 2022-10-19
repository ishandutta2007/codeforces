#include <bits/stdc++.h>
#define maxn (1<<21)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define debug printf
using namespace std;

pii dp[2][maxn];
int v[maxn];
pii last[maxn];

//vector<int> occ[maxn];
int occ1[maxn];
int occ2[maxn];


pii ret;
inline pii merge(pii a,pii b){
    if(a.second > b.second)
        return pii(max(a.first,b.second),a.second);
    else
        return pii(max(a.second,b.first),b.second);
    vector<int> u;
    u.pb(a.first);
    u.pb(a.second);
    u.pb(b.first);
    u.pb(b.second);
    sort(u.begin(), u.end());
    pii r;
    r.second = u[3];
    int id = 2;
    while(u[id] == u[3]) id--;
   if(id >= 0)r.first = u[id];
   else r.first = -1;
    return r;
}

int main(){
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<maxn;i++)
        occ1[i] = occ2[i] = -1;
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        if(i > occ2[v[i]]){
            occ1[v[i]] = occ2[v[i]];
            occ2[v[i]] = i;
        }   
        else if(i > occ2[v[i]])
            occ1[v[i]] = i;
    }
    for(int i=0;i<maxn;i++){
        
        last[i] = pii(occ1[i],occ2[i]);
    }
    
    for(int i=0;i<maxn;i++)
        dp[1][i] = last[i];
   // for(int i=0;i<8;i++)
     //   debug("last %d = %d %d\n",i,last[i].first,last[i].second);
        
    for(int i=20;i>=0;i--){
        for(int j=0;j<maxn;j++){
            int cur = i&1;
            int ot =1-cur;
            if(j & (1<<i)) {
                dp[cur][j] = dp[ot][j];
                continue;
            }
            int A = j;
            int B = j + (1<<i);
            dp[cur][j] = merge(dp[ot][A], dp[ot][B]);
           // if(i ==20 && j == 0) debug("mg %d %d | %d %d\n",dp[i+1][A].first,dp[i+1][A].second,dp[i+1][B].first,dp[i+1][B].second);
        //    if(j < 8 ) debug("dp %d %d = %d %d\n",i,j,dp[i][j].first,dp[i][j].second);
        }
        
        
    }
    
    for(int i=0;i<maxn;i++){
        if(dp[0][i].second >= 0)
           ;// debug("%d at %d %d\n",i,dp[0][i].first,dp[0][i].second);
        
        
    }
    int ans = 0;
    for(int i=20;i>=0;i--){
        
        int tenta = ans + (1<<i);
        int ok = 0;
        for(int j=0;j<n;j++){
            
            int falta = tenta - (tenta&v[j]);
            
            pii pos = dp[0][falta];
            if(pos.first > j) ok = 1;
            
        }
        
        if(ok) ans = tenta;
    }
        
    printf("%d\n",ans);
    
    
}