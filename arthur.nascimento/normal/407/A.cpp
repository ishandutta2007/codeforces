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
#define sq(x) ((x)*(x))

using namespace std;

main(){
        
        int a,b;
        scanf("%d%d",&a,&b);
        
        vector<pii> va;
        vector<pii> vb;
        
        for(int x=-1000;x<=1000;x++)
            for(int y=-1000;y<=1000;y++){
            
                if(x == 0 || y == 0) continue;
                
                if(x*x + y*y == a*a) va.pb(pii(x,y));
                if(x*x + y*y == b*b) vb.pb(pii(x,y));
                
            }
            
        #define x first
        #define y second    
                
        for(int i=0;i<va.size();i++)
            for(int j=0;j<vb.size();j++){
                
                pii u = va[i];
                pii v = vb[j];
              
                
                if(u.x == v.x || u.y == v.y) continue;
                
                if( sq(u.x-v.x) + sq(u.y-v.y) == a*a + b*b){
                    printf("YES\n0 0\n%d %d\n%d %d\n",u.x,u.y,v.x,v.y);
                    return 0;
                 }
                 
            }

        printf("NO\n");
        
}