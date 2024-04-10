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

#define mod 1000000007

using namespace std;

long long exp2(long long a,long long b){
     
     if(b==0)return 1;
     
     if(b == 1)return a;
     
     long long k = exp2(a,b/2) % mod;
     
     if(b % 2 == 0){
          
          return (k*k)%mod;
          
          }
     
     return (((k*k)%mod)*a)%mod;
     
     }

long long inv(long long a){
     
     return exp2(a%mod,mod-2);
     
     }

char v[100100];

main(){
       
       scanf("%s",v);
       
       long long n = strlen(v);
       long long k;
       cin >> k;
       
       long long resp = 0;
       
       for(int i=0;i<n;i++){
               
               if(v[i] != '0' && v[i] != '5')continue;
               
              // debug("i = %d a0 = %lld n = %d q = %lld\n",i,exp2(2,i),k,exp2(2,n));
               long long p = (exp2(2,i)*((exp2(2,k*n)-1+mod))%mod) % mod;
               p *= inv(exp2(2,n)-1+mod);
               resp = (resp + p)%mod;
               }
       
       cout << resp << endl;
       
       }