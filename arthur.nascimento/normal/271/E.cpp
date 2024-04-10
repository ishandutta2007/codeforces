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
#define maxn 200200

using namespace std;

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

main(){
        
        int n,m;
        scanf("%d%d",&n,&m);
        
        int g = 0;
        for(int i=0;i<n;i++){
            int u;
            scanf("%d",&u);
            g = gcd(g,u-1);
         }
         
         long long ans = 0;
         
         vector<int> div;
         
         for(int i=1;i*i<=g;i++) if(g%i == 0){
            div.pb(i);
            if(i*i != g) div.pb(g/i);
          }
          
          set<int> s;
          
          for(vector<int> :: iterator it = div.begin(); it < div.end(); it++)
            
                for(int i=*it;i<m;i*=2) s.insert(i);
         
          for(set<int> :: iterator it = s.begin(); it != s.end(); it++)
                
                ans += m - *it;
                
          printf("%I64d\n",ans);
          
}