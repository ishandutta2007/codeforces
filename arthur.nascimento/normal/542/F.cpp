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

vector<pii> v;

bool comp(pii a,pii b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

long long dp[1100][1010];
int ini[1100];
int n,T;

long long c[1100][1010];

long long get(int pos,int qnt){
    
    qnt = min(qnt,1001);
    if(pos == T+1) return 0;
    
    
    if(dp[pos][qnt]+1) return dp[pos][qnt];
    
    debug("get %d %d\n",pos,qnt);
    
    long long ret = 0;
    
    for(int i=0;i<=qnt;i++)
        ret = max(ret,c[pos][i]+get(pos+1,2*(qnt-i)));
    
   // debug("dp %d %d = %I64d u %d\n",pos,qnt,ret,ini[pos]-1);
    return dp[pos][qnt] = ret;
 
 
}
            

main(){

        scanf("%d%d",&n,&T);
        
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v.pb(pii(T-a,b));
         }
         
         sort(v.begin(), v.end(), comp);
         
         memset(c,0,sizeof(c));
         
         int p = 0;
         while(p < n){
            int p0 = p;
            while(v[p].first == v[p0].first && p < n) p++;
            int s = 0;
            for(int i=p0;i<p;i++){
                s += v[i].second;
                c[v[i].first][i-p0+1] = s;
                if(i != p0) assert(v[i].first == v[i-1].first && v[i].second <= v[i-1].second);
                debug("c %d %d = %d\n",v[i].first,i-p+1,s);
            }
        }
            
                
         memset(dp,-1,sizeof(dp));
         
         cout << get(0,1) << endl;
         
}