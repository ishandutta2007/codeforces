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

int pai[2][maxn];
int tam[2][maxn];

int block[2][maxn];

long long maior[2];

int find(int idx,int x){
    return pai[idx][x] = (x == pai[idx][x])  ? x : find(idx,pai[idx][x]);
}

void merge(int idx,int a,int b){
    debug("merge %d %d(%d)\n",a,b,idx);
    a = find(idx,a);
    b = find(idx,b);
    pai[idx][a] = b;
    tam[idx][b] += tam[idx][a];
    debug("tam := %d\n",tam[idx][b]);
    maior[idx] = max(maior[idx],(long long)tam[idx][b]);
}

main(){
    
        int w,h,n;
        scanf("%d%d%d",&w,&h,&n);
        
        vector<pii> q;
        
        for(int i=0;i<n;i++){
            char ch;
            int u;
            scanf(" %c%d",&ch,&u);
            q.pb(pii(ch,u));
            if(ch == 'V')
                block[0][u-1] = 1;
            else
                block[1][u-1] = 1;
        }
        
        for(int i=0;i<w;i++) pai[0][i] = i, tam[0][i] = 1;
        for(int i=0;i<h;i++) pai[1][i] = i, tam[1][i] = 1;
        
        maior[0] = maior[1] = 1;
        
        debug("ok\n");
        
        for(int i=0;i<w-1;i++)
            if(!block[0][i])
                merge(0,i,i+1);
        for(int i=0;i<h-1;i++)
            if(!block[1][i])
                merge(1,i,i+1);
                
        debug("ok\n");
                
        vector<long long> ans;
                
        for(int i=n-1;i>=0;i--){
        
            
            
            ans.pb(maior[0]*maior[1]);
            
            if(q[i].first == 'V')
                merge(0,q[i].second-1,q[i].second);
            else
                merge(1,q[i].second-1,q[i].second);
        
       }   
       
       reverse(ans.begin(), ans.end());
       for(int i=0;i<n;i++)
       cout << ans[i] << endl;
       
       
}