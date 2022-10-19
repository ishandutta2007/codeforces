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
  
int v[] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12}; 

char foi[100100];

  
main(){ 
  
    int n; 
    scanf("%d",&n); 
  
    int ans = 0; 
    int tot = 0; 
  
    for(int i=2;i*i<=n;i++) 
        if(!foi[i]){ 
            
            int qnt = 0; 
            for(long long k=i;k<=n;k*=i){ 
                    if(k < 100100)
                         foi[k] = 1;
                    qnt++,tot++; 
                    } 
            ans ^= v[qnt]; 
            } 
  
    printf("%s\n",(ans^((n-tot)%2)) ? "Vasya" : "Petya"); 
  
    }