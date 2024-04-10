#include <bits/stdc++.h>
#define maxn 200200
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) //printf(args)
using namespace std;
 
vector<int> L[maxn];
 
int dist[maxn];
int foi[maxn];
 
int pai[maxn];
int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}
void join(int a,int b){
    a = find(a);
    b = find(b);
    pai[a] = b;
}
 
int dp[20][maxn];
int prof[maxn];
 
void dfs(int vx,int p){
    if(vx == 0) prof[vx] = 0;
    else prof[vx] = 1 + prof[p];
    dp[0][vx] = p;
    for(int i=1;i<20;i++)
        dp[i][vx] = dp[i-1][dp[i-1][vx]];
    for(int k : L[vx]){
        if(k == p) continue;
        dfs(k,vx);
    }
}
 
int dd;
int lca(int a,int b){
    dd = 0;
    if(prof[a] < prof[b]) swap(a,b);
    int dh = prof[a] - prof[b];
    for(int i=0;i<20;i++)
        if(dh & (1<<i)){
            a = dp[i][a];
            dd += (1<<i);   
        }
            
    if(a == b) return a;
    
    for(int i=19;i>=0;i--)
        if(dp[i][a] != dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
            dd += 2*(1<<i);
        }
    dd+=2;
    return dp[0][a];
 
}
 
int Dist(int a,int b){
    lca(a,b);
    return dd;
}
 
inline int kth(int a,int b,int k,int l=-1){
    
    int L = l;
    if(L == -1) L = lca(a,b);
    
    int d1 = prof[a] - prof[L];
    int d2 = prof[b] - prof[L];
    
    if(k > d1){
        k = d1 + d2 - k;
        swap(a,b);
    }
  
    for(int i=0;i<17;i++)
        if(k & (1<<i))
            a = dp[i][a];
    return a;
    
}
 
int tenta(int a,int b,int dd,int t,int L,int r){
    
        if(prof[a] < prof[b]) swap(a,b);
    
        debug("a %d b %d\n",a,b);
        int mp = kth(a,b,dd);
        int cc = find(mp);
        
        int closeA, closeB;
        debug("t %d\n",t);

        int d1 = prof[a] - prof[L], d2 = prof[b] - prof[L];
        
        closeA = a;
        int dh = prof[a] - prof[mp];
        
        for(int i=18;i>=0;i--)
            if(dh > (1<<i)){
                int to = dp[i][closeA];
                if(pai[to] != cc){
                    closeA = to;
                    dh -= (1<<i);
                }
            }
            
        closeA = dp[0][closeA];
        if(pai[a] == cc) closeA = a;
        
        if(pai[L] == cc){
            closeB = b;
            dh = prof[b] - prof[L];
            for(int i=18;i>=0;i--)
            if(dh > (1<<i)){
                int to = dp[i][closeB];
                if(pai[to] != cc){
                    closeB = to;
                    dh -= (1<<i);
                }
            }
            closeB = dp[0][closeB];
            if(pai[b] == cc) closeB = b;
        }
        else {
            dh = prof[mp] - prof[L];
            closeB = mp;
            for(int i=18;i>=0;i--)
            if(dh > (1<<i)){
                int to = dp[i][closeB];
                if(pai[to] == cc){
                    closeB = to;
                    dh -= (1<<i);
                }
            }
        }
        
  
        
        debug("closeA %d closeB %d\n",closeA,closeB);
        
        int da = Dist(a,closeA), db = Dist(b,closeB);
        
        if(da + dist[closeA] <= r && db + dist[closeB] <= r)
            return 1;
        else
            return 0;
    
}
 
char ch;
inline void read(int &x){
    x = 0;
    while((ch=_getchar_nolock()) >= '0')
    x = 10*x + ch-'0';
}
 
int Q[maxn];
 
main(){
    
    int n,k,r;
   // scanf("%d%d%d",&n,&r,&k);
    read(n); read(r); read(k);
    for(int i=0;i<n-1;i++){
        int a,b;
    //    scanf("%d%d",&a,&b), a--, b--;
    read(a);
    read(b);
    a--, b--;
        L[a].pb(b);
        L[b].pb(a);
        
    }
    
    vector<int> v;  int ini = 0, fim =0 ;
    for(int i=0;i<k;i++){
        int x;
       // scanf("%d",&x), x--;
       read(x);
       x--;
        v.pb(x);
        Q[fim++] = x;
        foi[x] = 1;
    }
    
    for(int i=0;i<n;i++) pai[i] = i;
    
    while(ini < fim){
        
        int vx = Q[ini++];
        for(int viz : L[vx]){
            if(foi[viz]) continue;
            foi[viz] = 1;
            dist[viz] = 1 + dist[vx];
            join(vx,viz);
            Q[fim++] = viz;
        }
        
    }
 
    
    for(int i=0;i<n;i++)
        for(int viz : L[i])
            if(dist[i] + dist[viz] + 1 <= r)
                join(i,viz);
    
    
    for(int i=0;i<n;i++){
        debug("vx %d dist %d cc %d\n",i,dist[i],find(i));
    }
    
    for(int i=0;i<n;i++)
        find(i);
    
    dfs(0,0);
    int q;
   // scanf("%d",&q);
    read(q);
    while(q--){
        int a,b;
    //    scanf("%d%d",&a,&b), a--, b--;
    read(a);
    read(b);
    a--, b--;
        int L = lca(a,b);
        int d1 = prof[a] - prof[L], d2 = prof[b] - prof[L];
        if(d1+d2 <= r){
            printf("YES\n");
            continue;
        }
        int t = d1+d2;
        if(t <= 2*r){
            int A = kth(a,b,t/2);
            if(dist[A] + (t-t/2) <= r){
                printf("YES\n");
                continue;
            }
            int B = kth(a,b,t-t/2);
            if(dist[B] + t-t/2 <= r){
                printf("YES\n");
                debug("vx %d dist %d t %d r %d\n",B,dist[B],t,r);
                continue;
            }
        }
        
       /* int mp = kth(a,b,t/2);
        int cc = find(mp);
        
        int closeA, closeB;
        debug("t %d\n",t);
        int lo = 0, hi = t/2;
        while(1){
            debug("lo %d hi %d\n",lo,hi);
            int mid = (hi+lo)/2;
            closeA = kth(a,b,mid,L);
            if(hi == lo) break;
            if(find(closeA) == cc)
                hi = mid;
            else
                lo = mid+1;
        }
        
        lo = 0, hi = t-t/2;
        while(1){
            debug("2lo %d hi %d\n",lo,hi);
            int mid = (hi+lo)/2;
            closeB = kth(b,a,mid,L);
            if(hi == lo) break;
            if(find(closeB) == cc)
                hi = mid;
            else
                lo = mid+1;
        }*/
        
   
        
        
        if(tenta(a,b,t/2,t,L,r))
            printf("YES\n");
        else
            printf("NO\n");
        
        
        
    }
    
}