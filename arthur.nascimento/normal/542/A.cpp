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

struct ev {
    int l,r,val,idx;
    ev(int l=0,int r=0,int val=0,int idx=0): l(l), r(r), val(val), idx(idx) {}
}

v[400400],
nn[200200],
mm[200200];

bool comp1(ev a,ev b){
    if(a.r == b.r)if((a.val == 0) ^ (b.val == 0))
        return a.val == 0;
    return a.r > b.r;
}

bool comp2(ev a,ev b){
    if(a.l == b.l)if((a.val == 0) ^ (b.val == 0))
        return a.val == 0;
    return a.l < b.l;
}

bool comp3(ev a,ev b){
    if(a.l == b.l)if((a.val == 0) ^ (b.val == 0))
        return a.val == 1;
    return a.l < b.l;
}

long long ans = 0;
long long ans1;
int tipo = 0;

long long testa(int a,int b){

    long long u = 0;
    if(mm[b].r >= nn[a].r && mm[b].l <= nn[a].l) u = nn[a].r - nn[a].l;
    else if(mm[b].r <= nn[a].r && mm[b].l >= nn[a].l) u = mm[b].r - mm[b].l;
    else if(nn[a].r > mm[b].l && nn[a].r <= mm[b].r) u = nn[a].r - mm[b].l;
    else if(mm[b].r > nn[a].l && mm[b].r <= nn[a].r) u = mm[b].r - nn[a].l;
    
    return u * mm[b].val;

}


main(){
        
        int n,m;
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            v[i] = ev(l,r,0,i);
            nn[i] = ev(l,r,0,i);
        }
        for(int i=0;i<m;i++){
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            v[i+n] = ev(l,r,val,i);
            mm[i] = ev(l,r,val,i);
        }
        
        int N = n+m;
        
        
        sort(v,v+N,comp1);
        
        int mi = 1000000001;
        
        for(int i=0;i<N;i++){
        
            debug("i=%d\n",i);
            
            if(v[i].val == 0){
                mi = min(mi,v[i].l);
                debug("mrk %d\n",v[i].l);
            }
            else {
                int u = 0;
                if(mi <= v[i].l) u = v[i].r-v[i].l;
                else u = v[i].r-mi;
                long long c = (long long)v[i].val * u;
               // debug("%d~%d -> %I64d\n",v[i].l,v[i].r,c);
                if(c > ans){
                    ans = c;
                    ans1 = v[i].idx;
                }
            }
            
        }
        
        sort(v,v+N,comp2);
        
        int ma = -1;
        
        for(int i=0;i<N;i++){
        
            debug("i=%d\n",i);
            
            if(v[i].val == 0)
                ma = max(ma,v[i].r);
            else {
                int u = 0;
                if(ma >= v[i].r) u = v[i].r-v[i].l;
                else u = ma-v[i].l;
                long long c = (long long)v[i].val * u;
                //debug("%d~%d -> %I64d\n",v[i].l,v[i].r,c);
                if(c > ans){
                    ans = c;
                    ans1 = v[i].idx;
                }
            }
            
        }
        
        sort(v,v+N,comp3);
        
        set<pii> S;
        
        for(int i=0;i<N;i++){
        
            debug("i=%d tam = %d\n",i,(int)S.size());
            
            if(v[i].val){
                
                debug("!\n");
                pii u (v[i].r,v[i].val);
                debug("insert %d %d\n",u.first,u.second);
                S.insert(u);
                set<pii> :: iterator it = S.upper_bound(u);
                if(it != S.end()) if(it->second > v[i].val) {
                    debug("tira u it = %d %d\n",it->first,it->second);
                    S.erase(u);
                    continue;
                }
                it = S.find(u);
                while(1){
                    if(it == S.begin()) break;
                    set<pii> :: iterator it2 = it;
                    it2--;
                    if(v[i].val >= it2->second) S.erase(it2);
                    else break;
                }
                continue;
            
            }
            
            set<pii> :: iterator it = S.upper_bound(pii(v[i].r,-1));
            if(it == S.end()) continue;
            long long c = (long long)(it->second) * (v[i].r-v[i].l);
           // debug("%d~%d -> %I64d\n",v[i].l,v[i].r,c);
            if(c > ans){
                ans = c;
                tipo = 1;
                ans1 = v[i].idx;
            }
            
       }
       
       cout << ans << endl;
       if(ans == 0) return 0;
       
       debug("! %d\n",tipo);
       
       
       if(tipo == 0){
            int a=-1, b=ans1;
            for(int i=0;i<n;i++)
                if(testa(i,b) == ans) a = i;
            printf("%d %d\n",a+1,b+1);
       }
       
       else {
            int a=ans1, b=-1;
            for(int i=0;i<m;i++)
                if(testa(a,i) == ans) b = i;
            printf("%d %d\n",a+1,b+1);
       }      
           
}