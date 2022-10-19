#include <bits/stdc++.h>
#define maxn 150150
#define maxA 1001000
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug
using namespace std;

map<pii,int> ans;

int mrk[maxA];
int v[maxn];
int sieve[maxA];

int pai[maxA];
int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

vector<int> comp[maxA];

set<int> adj1[maxA];

int main() {
    
    int n,q;
    scanf("%d%d",&n,&q);
    
    sieve[1] = 1;
    
    for(int i=2;i<maxA;i++)
        if(sieve[i] == 0){
            for(int j=i;j<maxA;j+=i)
                if(sieve[j] == 0)
                    sieve[j] = i;
        }
    
    for(int i=1;i<maxA;i++)
        pai[i] = i;
    
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        mrk[v[i]] = 1;
        vector<int> pr;
        int aux = v[i];
        while(aux != 1){
            pr.pb(sieve[aux]);
            aux /= sieve[aux];
        }
        for(int j : pr){
            pai[find(pr[0])] = find(j);
            debug("merge %d %d\n",pr[0],j);   
        }
    }
    
    for(int i=0;i<maxA;i++) find(i);
    
    for(int i=2;i<maxA;i++)
        if(sieve[i] == i)
            comp[pai[i]].pb(i);
                
    for(int i=0;i<n;i++){
            
        int aux = v[i] + 1;
        while(aux != 1){
            adj1[pai[sieve[v[i]]]].insert(pai[sieve[aux]]);
            aux /= sieve[aux];
        }
            
    }
    
    while(q--){
        
        int x,y;
        scanf("%d%d",&x,&y);
        
        x = find(sieve[v[x-1]]);
        y = find(sieve[v[y-1]]);
        
        debug(": %d %d\n",x,y);
        
        if(ans[{x,y}]){
            printf("%d\n",ans[{x,y}]);
            continue;
        }
        
        if(x == y){
            printf("0\n");
            continue;
        }
        
        if(adj1[x].find(y) != adj1[x].end() || adj1[y].find(x) != adj1[y].end()){
            printf("1\n");
            continue;
        }
        
        ans[{x,y}] = 2;
        
        for(int X : comp[x])
            for(int Y : comp[y]){
                
                
                if((ll) X * Y >= maxA-1) break;
                
                for(int k=1; k * X * Y < maxA; k++)
                
                    if(mrk[k*X*Y-1]){
                        ans[{x,y}] = 1;
                        break;
                    }
                
            }
            
        printf("%d\n",ans[{x,y}]);
        
    }
    
}