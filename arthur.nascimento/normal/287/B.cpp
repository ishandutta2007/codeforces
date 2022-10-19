#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <assert.h>
#include <queue>
#define debug 
using namespace std;

unsigned  long long k;
unsigned long long n;

unsigned long long sigma(long long x){
     
   // debug("sig %lld = %lld\n",x,(k*(k+1))/2 - (x*(x-1))/2);
     return ((k*(k+1))/2) - ((x*(x-1))/2);
     
     }

 long long bsearch(long long init,long long fim){
    
    debug("%d ~ %d\n",init,fim);
    if(init==fim)assert(sigma(init) >= n);
    if(fim-init<=1)
                    return (sigma(fim) >= n)?fim:init;
                    
    
    long long meio = (init+fim)/2;

    if(sigma(meio) >= n)return bsearch(meio,fim);
    
    else return bsearch(init,meio);
    
    
}

main(){
       
       
       
       
       cin >> n >> k;
       k--;
       n--;
       
       if(sigma(1)<n)printf("-1\n");
       else
       
       cout << k+1-bsearch(1,k+1) << endl;
      
       };