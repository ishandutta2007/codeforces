#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <queue>
#include <map>
#define pii pair<int,int>

#ifdef ONLINE_JUDGE
#define debug
#else
#define debug printf
#endif

using namespace std;

pii aresta[100100];

vector<int> L [100100];
int grau[100100];
int pai[100100][20];
int prof[100100];
int achou[100100];
int mrk[100100];

map<pii,int> mp;

void dfs(int x,int p){
     
     achou[x] = 1;
     pai[x][0] = p;
     
      
     
     if(x == 0)
          prof[x] = 0;
     else
         prof[x] = prof[p] + 1;
     
     for(int i=0;i<grau[x];i++)
             if(!achou[L[x][i]])
                    dfs(L[x][i],x);
     
     }

int getlca(int a,int b){
    
    if(prof[a] > prof[b])
               swap(a,b);
    
    if(a == b)
         return a;
         
    int dh = prof[b] - prof[a];
    
    for(int i=0;i<20;i++)
            if(dh & (1 << i))
                  b = pai[b][i];
    
    if(a == b)
         return a;
         
    for(int i=19;i>=0;i--){
            
            if(pai[a][i] != pai[b][i]){
                         a = pai[a][i];
                         b = pai[b][i];
                         }
            
            }
    
    return pai[a][0];
}

main(){
       
       int n;
       scanf("%d",&n);
       
       for(int i=0;i<n-1;i++){
               scanf("%d%d",&aresta[i].first,&aresta[i].second);
               
               if(aresta[i].first > aresta[i].second)
                                  swap(aresta[i].first,aresta[i].second);
               
               aresta[i].first--;
               aresta[i].second--;
               L[aresta[i].first].push_back(aresta[i].second);
               L[aresta[i].second].push_back(aresta[i].first);
               grau[aresta[i].second]++;
               grau[aresta[i].first]++;
               }
       
       
       dfs(0,0);
       
       for(int i=1;i<20;i++)
               for(int j=0;j<n;j++)
                       pai[j][i] = pai[pai[j][i-1]][i-1];
       
       int k;
       scanf("%d",&k);
       
       for(int i=0;i<k;i++){
               
               int a,b;
               scanf("%d%d",&a,&b);

               int lca = getlca(a-1,b-1);
               
               debug("lca = %d\n",lca);
               
               mrk[a-1]++;
               mrk[b-1]++;
               mrk[lca] -= 2;
               
               }

     queue<int> Q;
     
     for(int i=0;i<n;i++)
             if(grau[i] == 1)
                        Q.push(i);
     
     while(!Q.empty()){
                       
                       int k = Q.front();
                       Q.pop();
                       
                       debug("mrk %d = %d\n",k,mrk[k]);
                       
                       mp[pii(min(k,pai[k][0]),max(k,pai[k][0]))] += mrk[k];
                       
                       mrk[pai[k][0]] += mrk[k];
                       
                       if(--grau[pai[k][0]] == 1)
                                            Q.push(pai[k][0]);
                       
                       }
     
     for(int i=0;i<n-1;i++){
             
             printf("%d ",mp[aresta[i]]);
             
             }

           
             }