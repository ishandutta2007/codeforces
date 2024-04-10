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

int v[110];
int sum[110];

main(){
       
       int n;
       scanf("%d",&n);
       
       for(int i=0;i<n;i++)
               scanf("%d",v+i);
               
       sum[0] = v[0];
       
       for(int i=1;i<n;i++)
               sum[i] = sum[i-1] + v[i];
       
       int ans = 0;
               
       for(int i=0;i<n;i++){
               for(int j=i;j<n;j++){
                       
                       int r = 0;
                       
                       for(int k=0;k<n;k++){
                               
                               if(k >= i && k<=j)r += (v[k]^1);
                               else r += v[k];
                               }
                       ans = max(ans,r);
                       }}
       
       printf("%d\n",ans);
  
       }