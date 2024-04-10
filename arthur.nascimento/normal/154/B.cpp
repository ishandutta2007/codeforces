#include <iostream>
#include <iomanip>
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
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 100100		
#define mod 1000000007
 
using namespace std;


int sieve[maxn];

int state[maxn];

set<int> S[maxn];

main(){

        for(int i=2;i<maxn;i++) if(sieve[i] == 0)
                for(int j=i;j<maxn;j+=i) sieve[j] = i;
        
        int n,q;
        scanf("%d%d",&n,&q);
        
        
        while(q--){
                char ch;
                int u;
                scanf(" %c %d",&ch,&u);
                debug("%c %d\n",ch,u);
                int aux = u;
                
                if(ch == '-'){
                        if(state[u] == 0)
                                printf("Already off\n");
                        else
                                printf("Success\n");
                        state[u] = 0;
                        while(aux != 1){
                                S[sieve[aux]].erase(u);
                                aux /= sieve[aux];
                        }
                }
                
                else {
                        if(state[u] == 1){
                                printf("Already on\n");
                                continue;
                         }
                         int ok = 1;
                         int qual;
                         while(aux != 1){
                                debug("aux %d p %d\n",aux,sieve[aux]);
                                if(S[sieve[aux]].size()){
                                        ok = 0;
                                        qual = *S[sieve[aux]].begin();
                                }
                                aux /= sieve[aux];
                        }
                        
                        if(!ok){
                                printf("Conflict with %d\n",qual);
                                continue;
                        }
                        
                        state[u] = 1;
                        aux = u;
                        while(aux != 1){
                               S[sieve[aux]].insert(u);
                               aux /= sieve[aux];
                        }
                        printf("Success\n");
                  
                 }       
          
          }
          
}