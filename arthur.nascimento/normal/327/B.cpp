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

int primo(int x){
    
    for(int i=2;i*i<=x;i++)
            if(x%i == 0)return 0;
    return 1;}
    
main(){
       
       int n;
       scanf("%d",&n);
       
       int cont = 0;
       for(int i=2;cont < n;i++){
               
               if(primo(i)){
                            printf("%d\n",i);
                            cont++;
                            }
               }
    }