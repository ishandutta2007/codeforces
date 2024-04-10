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
#include <complex>

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
#define maxn 100100
#define mod 1000000007

using namespace std;

vector<int> L[maxn];
int cc[maxn];
int foi[maxn];
int color[maxn];

int ok = 1;

void dfs(int x,int c,int cor=0){
    if(foi[x]) return;
    color[x] = cor;
    foi[x] = 1;
    cc[x] = c;
    for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) {
        if(!foi[*it]) dfs(*it,c,cor^1);
        else if(color[x] == color[*it]) ok = 0;
    }    
       
}

main(){

        int n,m;
        scanf("%d%d",&n,&m);
        vector<pii> bad;
        
        for(int i=0;i<m;i++){
            int a,b,u;
            scanf("%d%d%d",&a,&b,&u), a--, b--;
            if(u) L[a].pb(b), L[b].pb(a);
            else bad.pb(pii(a,b));
        } 
        
        int c = 0;
        for(int i=0;i<n;i++) if(!foi[i]){
            dfs(i,c);
            c++;
        }
        
        for(int i=0;i<n;i++) L[i].clear();
        
        for(vector<pii> :: iterator it = bad.begin(); it < bad.end(); it++){
            if(cc[it->first] == cc[it->second]) ok = 0;
            L[cc[it->first]].pb(cc[it->second]);
            L[cc[it->second]].pb(cc[it->first]);
        }
        
        memset(color,0,sizeof(color));
        memset(foi,0,sizeof(foi));
        ok = 1;
        
        int e = 0; debug("c=%d\n",c);
        for(int i=0;i<c;i++) if(!foi[i]){
        
            dfs(i,e,0);
            e++;
        }
        
        
        long long ans = 1;
        for(int i=0;i<e-1;i++) ans = (ans*2) % mod;
        if(!ok) ans = 0;
        
        cout << ans << endl;
        
        
  }