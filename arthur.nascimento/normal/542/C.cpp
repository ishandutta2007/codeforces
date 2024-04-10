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
#define mod 1000000007
#define maxn 220

using namespace std;

int happy[maxn];
int f[maxn];

int foi[maxn];

long long gcd(long long a,long long b){
    return b ? gcd(b,a%b): a;}

long long lcm(long long a,long long b){
    return (a*b)/gcd(a,b);
}

main(){
        
        int n;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
            scanf("%d",f+i), f[i]--;
            
          
         long long t = 1;
         long long ma = 0;
          
         for(int i=0;i<n;i++){
         
            memset(foi,0,sizeof(foi));
            
            int u = i;
            long long len = 0;
            while(!foi[u]){
                len++;
                foi[u] = 1;
                u = f[u];
            }
            
            if(u == i){
                happy[i] = 1;
                t = lcm(t,len);
            }
                
         }
         
         for(int i=0;i<n;i++) if(!happy[i]){
            
            int u = i;
            long long len = 0;
            while(!happy[u]){
                u = f[u];
                len++;
            }
            
            ma = max(ma,len);
                
         }
         
         long long ans = t;
         while(ans < ma)ans += t;
         
         cout << ans << endl;
         
}