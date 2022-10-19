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
#define maxn 2020
#define mod 1000000007
 
using namespace std;

int prime(int x){
    if(x==1) return 0;
    for(int i=2;i*i<=x;i++) if(x%i == 0) return 0;
    return 1;
}


char str[13];
int pali(int x){
    int len = 0;
    while(x){
        str[len++] = x%10;
        x/=10;
     }
     for(int i=0;i<len;i++)
        if(str[i] != str[len-i-1]) return 0;
     return 1;
}

main(){
    
        long long p,q;
        cin >> p >> q;
        
        int pi = 0;
        int pal = 0;
        int cont = 1000;
        int ans = -1;
        
        for(int i=1;1;i++){
            
            if(prime(i))pi++;
            if(pali(i))pal++;
            if(q*pi <= p*pal) ans = i;
            
            cont--;
            if(cont == 0){
                cont = 1000;
                if(clock() > 2.8 * CLOCKS_PER_SEC) break;
            }
            
         }
         
         if(ans+1)
            printf("%d\n",ans);
          else
            printf("Palindromic tree is better than splay tree\n");
            
 }