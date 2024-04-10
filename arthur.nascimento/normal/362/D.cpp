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

vector<int> L[100100];
long long sum[100100];

int achou[100100];

long long dfs(int x){
     
     achou[x] = 1;
     
     long long ret = sum[x];
     
     for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
                     if(!achou[*it])
                                    ret += dfs(*it);
     
     return ret;}

struct city {
       long long sum;
       int v;
       city(long long sum = 0,int v=0) : sum(sum), v(v){}
       bool operator<(city comp)const{
            return sum > comp.sum;}
};

main(){
       
       int n,m,c,cf;
       scanf("%d%d%d%d",&n,&m,&c,&cf);
       
       for(int i=0;i<m;i++){
               int a,b;
               long long p;
               scanf("%d%d%I64d",&a,&b,&p);
               a--,b--;
               sum[a] += p;
               sum[b] += p;
               L[a].push_back(b);
               L[b].push_back(a);
               }
               
       priority_queue<city> Q;
       
       int comps = 0;
       
       for(int i=0;i<n;i++)
               if(!achou[i]){
                             comps++;
                             long long k = dfs(i)/2;
                             Q.push(city(k,i));
                             debug("push %I64d %d\n",k,i);
                             }
                             
       
       debug("comps = %d\n",comps);
       
       if(comps < cf || comps > c + cf || (comps == cf && m == 0 && c != 0)){
                printf("NO\n");
                return 0;}
                
       printf("YES\n");
       
       pii aaa = pii(-1,-1);
       
       for(int i=0;i<comps-cf;i++){
               
               city A = Q.top();
               Q.pop();
               city B = Q.top();
               Q.pop();
               
               printf("%d %d\n",A.v+1,B.v+1);
               aaa = pii(A.v,B.v);
               
               Q.push(city(A.sum+B.sum+min(1000000000LL,A.sum+B.sum+1), A.v));
               
               }
               
       c -= (comps - cf);
       
       if(aaa == pii(-1,-1)){
              
              if(m == 0)
                   aaa = pii(0,1);
              else {
                   for(int i=0;i<n;i++)
                           if(L[i].size())
                                          aaa = pii(i,*(L[i].begin()));
                   
                   }
              
              }
       
       for(int i=0;i<c;i++)
               printf("%d %d\n",aaa.first+1,aaa.second+1);
               
               }