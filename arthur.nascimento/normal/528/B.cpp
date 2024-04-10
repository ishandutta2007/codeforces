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
#define pim pair<int,multiset<int> >
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

main(){
    
        int n;
        scanf("%d",&n);
        
        vector<pii> v;
        
        for(int i=0;i<n;i++){
            int x,w;
            scanf("%d%d",&x,&w);
            v.pb(pii(x+w,x-w));
        }
        
        sort(v.begin(), v.end());
        
        long long last = -inf;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(v[i].second >= last){
                ans++;
                last = v[i].first;
            }
        }
        
        printf("%d\n",ans);
}