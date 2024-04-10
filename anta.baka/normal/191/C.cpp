// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#define ONLINE_JUDGE 1
/*
                                                             
                                                               
                                                                
                                                                  
                                                                    
                                                                 
                                                                 
                                                                 
                                                                  
                                                                   
                                                                      
                                                                    
                                                                
                                                        
                                              
                                     
                   
                      
                   
                    
                   
                           
                           
                         
                       
                      
                     
                      
                        
                         
                        
                        
                       
                      
                     
                          
                          
                          
                      
                      
                     
                      
                            
                            
                                    
                                    
                                       
                                               
                                                   
                                                    
                                                        
                                                           
                                                            
                                                                
                                                            
                                                              
                                                            
                                                             
                                                            
                                                         
                                                         
                                                         
                                                        
                                                  
                                               
                                         
                                     
                                            
                                            
                                         
                                     
                                  
                                  
                                       
                                      
                               
                               
*/
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

int V, Q, DFSTime = 0;
vector<ii> g[100000];
int ans[99999], d[100000], st[100000][18], par[100000];
int tin[100000], tout[100000];

void dfs1(const int &v, const int &p = 0) {
    par[v] = p;
    tin[v] = DFSTime++;
    st[v][0] = p;
    for(int i = 1;i < 18;i++)
        st[v][i] = st[st[v][i - 1]][i - 1];
    for(const ii &to : g[v]) {
        if(to.X != p) {
            dfs1(to.X, v);
        }
    }
    tout[v] = DFSTime++;
}

bool is_parent(const int &v, const int &p) {
    return (tin[p] <= tin[v] && tout[v] <= tout[p]);
}

int LCA(const int &u, const int &v) {
    if(is_parent(u, v)) return v;
    if(is_parent(v, u)) return u;
    int x = v, deg = 17;
    while(deg >= 0) {
        if(!is_parent(u, st[x][deg]))
            x = st[x][deg];
        deg--;
    }
    return max(par[x], 0);
}

void dfs2(const int &v, const int &p = 0) {
    for(const ii &to : g[v]) {
        if(to.X != p) {
            dfs2(to.X, v);
            d[v] += d[to.X];
            ans[to.Y] = d[to.X];
        }
    }
}

void solve() {
    scanf("%d", &V);
    for(int i = 0;i < V - 1;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[v].push_back(ii(u, i));
        g[u].push_back(ii(v, i));
    }
    dfs1(0);
    scanf("%d", &Q);
    while(Q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        int lca = LCA(a, b);
        if(lca == a || lca == b) {
            int v = a + b - lca;
            d[v]++;
            d[lca]--;
        } else {
            d[a]++;
            d[b]++;
            d[lca] -= 2;
        }
    }
    dfs2(0);
    for(int i = 0;i < V - 1;i++)
        printf("%d ", ans[i]);
}

int main() {
    if(!ONLINE_JUDGE) { //usual problem
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}