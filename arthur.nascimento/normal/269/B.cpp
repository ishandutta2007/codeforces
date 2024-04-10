#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int v[5050];
int dp[5050][5050];
int sum[5050][5050];
int n,m;

int get(int x,int foi){
 
    if(x==n)return 0;
    if(dp[x][foi]+1)return dp[x][foi];
    

    
    if(v[x] <= foi)
            return dp[x][foi] = get(x+1,foi)+1;
    
    return dp[x][foi] = min(get(x+1,foi)+1,get(x+1,v[x]-1));
              
    
}

main(){
       scanf("%d%d",&n,&m);
       float lixo;
       
       memset(dp,-1,sizeof(dp));
       
       scanf("%d %f",v,&lixo);
       
       sum[v[0]][0]=1;
       
       for(int i=1;i<n;i++){
               scanf("%d %f",v+i,&lixo);
               
               for(int j=0;j<m;j++)
               sum[j][i] = sum[j][i-1];
               
               sum[v[i]][i]++;
               
               }
               
       printf("%d",get(0,0));
 }