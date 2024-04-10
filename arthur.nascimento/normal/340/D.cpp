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

int T[100100];

int query(int idx){
     int ret = 0;
     while(idx){
                ret = max(ret,T[idx]);
                idx -= idx&-idx;
                }
     return ret;}
     
void update(int idx,int val){
     while(idx < 100100){
               T[idx] = max(T[idx],val);
               idx += idx&-idx;
               }
     }

main(){
       
       int n;
       scanf("%d",&n);
       int resp = 0;
       
       for(int i=0;i<n;i++){
               int k;
               scanf("%d",&k);
               int v = query(k-1);
               resp = max(resp,1+v);
               update(k,v+1);}
       
       printf("%d\n",resp);}