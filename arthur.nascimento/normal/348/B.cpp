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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

vector<int> L[100100];
int v[100100];
int achou[100100];
int tira[100100];
int best = 999999999;
int lol = 0;
long long sum = 0;

long long gcd(long long a,long long b){
     return b ? gcd(b,a%b) : a;}

long long lcm(long long a,long long b){
     return (a*b) / gcd(a,b);}

long long dfs(int x){
     
     achou[x] = 1;
     
     if(v[x])
             return 1;
     
     long long ret = 1;
     
     for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
                     if(!achou[*it]){
                                    ret = lcm(ret,dfs(*it));
                                    //if(ret > 10000000000000LL)lol = 1;
                                    }
      
     debug("%d %d\n",x,L[x].size());
     
     if(x)         
                   ret *= (L[x].size()-1);
     else          ret *= L[x].size();
     
     if(ret > 10000000000000LL)
            lol = 1;
     
     return ret;}
     
void dfs2(int x,long long k){
     
     achou[x] = 1;
     
     int dg = x ? L[x].size()-1 : L[x].size();
     
     if(v[x]){
              debug("v %d k = %d\n",x,k);
              tira[x] = k;
              best = min(best,v[x]/tira[x]);
              }
     
     for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
                     if(!achou[*it])
                                    dfs2(*it,k/dg);
     
     
     }


main(){
       
       int n;
       scanf("%d",&n);
       
       for(int i=0;i<n;i++){
               scanf("%d",v+i);
               sum += v[i];
               }
               
       for(int i=0;i<n-1;i++){
               int a,b;
               scanf("%d%d",&a,&b);
               L[a-1].push_back(b-1);
               L[b-1].push_back(a-1);}
               
       for(int i=1;i<n;i++){
               if(L[i].size() == 1 && v[i] == 0){
                              long long ans = 0;
                              for(int i=0;i<n;i++)ans += v[i];
                              
                              cout << ans << endl;
                              return 0;
                              }
               }
               
       long long k = dfs(0);
       memset(achou,0,sizeof(achou));
       debug("k = %d\n",k);
       if(lol){
               
               cout << sum << endl;
               return 0;}
       dfs2(0,k);
       
       long long ans = 0;
       
       debug("best = %d\n",best);
       
       for(int i=0;i<n;i++)
               if(v[i])
                       ans += v[i] - best * tira[i];
       if(ans == 62263648)cout << "k = " << k << endl;               
       cout << ans << endl;

}