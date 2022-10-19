#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <assert.h>
#define debug
#define INF 2500000000000000000LL
#define min2(a,b) ((a<b)?a:b)
using namespace std;

int prioridade[220*2];
int resp[220*2];
int fixo[220*2];
unsigned long long dp[220*2][220*2];
int M[110*2][110*2];
int v[220*2];

int n,m;

bool comp(int a,int b){
     return prioridade[a] < prioridade[b];}
     
unsigned long long get(int x,int qnt){
    
    debug("x=%d qnt=%d fixo[%d]=%d\n",x,qnt,x,fixo[x]);
    
    if(qnt == -1)return 0;
    
    if(dp[x][qnt]+1)return dp[x][qnt];
    
    if(x == n+m-1)
               return (qnt==0) ? 1 : 0;
         
    if(fixo[x])
               return dp[x][qnt] = min2(INF,get(x+1,qnt+resp[x]));
    
    return dp[x][qnt] = min2(INF, get(x+1,qnt-1) + get(x+1,qnt+1)); 
    
    }

main(){
       
       
       long long k;
       
       scanf("%d%d",&n,&m);
       cin >> k;
       
       for(int i=0;i<220;i++)
               prioridade[i] = 999999999;
       
       for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                       
                       scanf("%d",&M[i][j]);
                       
                       prioridade[i+j] = min(prioridade[i+j],M[i][j]);
                       
                       }}
                       
       for(int i=0;i<n+m-1;i++)
               v[i] = i;
       
       sort(v,v+n+m-1,comp);
       
       for(int i=0;i<n+m-1;i++){
               
               debug("fixa %d\n",v[i]);
               
               assert(!fixo[v[i]]);
               fixo[v[i]] = 1;
               resp[v[i]] = 1;
               
               memset(dp,-1,sizeof(dp));
               
               if(get(0,0) < k){
                           k -= get(0,0);
                          
                           resp[v[i]] = -1;
                           }
             
               
               }
              
       
       assert(k==1);
       for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                       printf("%c",(resp[i+j]==1)?'(':')');
                       if(resp[i+j]==0)printf("?");
                       }
                       printf("\n");}
                         }