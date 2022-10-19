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
#define maxn 100100

using namespace std;

int w[1010]; 

main(){  

        int n,k;
        scanf("%d%d",&n,&k);
        
        int ans = 0;
        vector<int> pref;
        
        for(int i=0;i<n;i++)
            scanf("%d",w+i);
            
        for(int i=0;i<k;i++){
            
            int a;
            scanf("%d",&a), a--;
            
            vector<int> novo;
            novo.pb(a);
            
            int foi = 0;
            for(int j=0;j<pref.size();j++){
                if(pref[j] == a) foi = 1;
                else novo.pb(pref[j]);
                if(!foi) ans += w[pref[j]];
            }
            
            pref = novo;
            
            
        }
        
        printf("%d\n",ans);
        
}