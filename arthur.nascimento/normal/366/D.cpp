#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

vector<int> L [1010];
vector<pii> interv[1010];
int v[3030];
int achou[1010];

int l,r;

void dfs(int x){
     
     debug("achou %d\n",x);
     achou[x] = 1;
     
     vector<int> :: iterator it = L[x].begin();
     vector<pii> :: iterator it2 = interv[x].begin();
     
     for(;it < L[x].end(); it++, it2++)
                     if(!achou[*it] && l >= it2 -> first && r <= it2 -> second)
                                    dfs(*it);
                                    
}

main(){
       
       int n,m;
       scanf("%d%d",&n,&m);
       
       for(int i=0;i<m;i++){
               int a,b,l,r;
               scanf("%d%d%d%d",&a,&b,&l,&r);
               a--,b--,l--,r--;
               L[a].push_back(b);
               L[b].push_back(a);
               interv[a].push_back(pii(l,r));
               interv[b].push_back(pii(l,r));
               v[i] = l;
               }
               
       int a=0,b=1000000000;
       
       while(a != b){
               
               int med = (a+b+1)/2;
               
               debug("med = %d\n",med);
               
               int ok = 0;
               
               for(int i=0;i<m;i++){
                       
                       memset(achou,0,sizeof(achou));
                       l = v[i];
                       r = v[i] + med - 1;
                       
                       debug("%d~%d i=%d m=%d\n",l,r,i,m);
                       
                       dfs(0);
                       
                       if(achou[n-1])
                                     ok = 1;
                       
                       }
               
               if(ok)
                     a = med;
               else
                   b = med - 1;
               
               }
               
               if(a == 0)
                    printf("Nice work, Dima!\n");
               else
                   printf("%d\n",a);


}