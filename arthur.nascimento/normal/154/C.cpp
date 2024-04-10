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
#define maxn 1001000		
#define mod 1000000007
 
using namespace std;

pll val[maxn];
pll t[maxn];
map<pll,long long> mp;

main(){
        
        int n,m;
        scanf("%d%d",&n,&m);
        
        srand(time(0));
        vector<pii> v;
        
        for(int i=0;i<n;i++)
                val[i].first = (long long)rand()*rand() + rand(),
                val[i].second = (long long)rand()*rand() + rand();
        
        for(int i=0;i<m;i++){
                int a,b;
                scanf("%d%d",&a,&b), a--, b--;

                v.pb(pii(a,b));
                t[a].first ^= val[b].first;
                t[a].second ^= val[b].second;
                t[b].first ^= val[a].first;
                t[b].second ^= val[a].second;
         }
         
         long long ans = 0;
         
         for(int i=0;i<m;i++)
                if( (t[v[i].first].first^val[v[i].second].first) == (t[v[i].second].first^val[v[i].first].first) && (t[v[i].first].second^val[v[i].second].second) == (t[v[i].second].second^val[v[i].first].second)) ans++;
                
         sort(t,t+n);
         
         int pos = 0;
         while(pos < n){
                int p0 = pos;
                while(pos < n && t[pos].first == t[p0].first && t[pos].second == t[p0].second) pos++;
                
                long long u = pos-p0;
              
                
                ans += (u*(u-1))/2;
         }
         
         
         
                
         cout << ans << endl;
   
}