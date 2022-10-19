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
#define maxn 2202000

using namespace std;

typedef long long ll;

int ans[200200];

struct Query {
    int x,y,idx;
    Query(int x=0,int y=0,int idx=0): x(x), y(y), idx(idx) {}
    bool operator<(Query comp) const {
        return x > comp.x;
    }
}

Q[200200];

bool cmp(pii a,pii b){
    return a.first > b.first;
}

int cont = 2;

int l[8*maxn];
int r[8*maxn];
int T[8*maxn];
char lazy[8*maxn];

void refresh(int init,int fim,int p){
	if(lazy[p] == 0) return;
	T[p] = fim-init+1;
	if(init != fim) lazy[l[p]] = lazy[r[p]] = 1;
}

void update(int init,int fim,int p,int a,int b){

	debug("upd %d-%d (%d) %d %d\n",init,fim,p,a,b);
	if(r[p] == 0)r[p] = cont++;
	if(l[p] == 0)l[p] = cont++;
	if(cont >= 8*maxn) exit(0);

	refresh(init,fim,p);

	if(init > b || fim < a) return;

	if(init >= a && fim <= b){
		lazy[p] = 1;
		refresh(init,fim,p);
		return;
	}

	int mid = ((long long)init+fim)/2;
	if(a <= mid)
		update(init,mid,l[p],a,b);
	if(b > mid)
		update(mid+1,fim,r[p],a,b);

	T[p] = T[l[p]] + T[r[p]];
	if(lazy[p]) T[p] = fim-init+1;
    
}

int query(int init,int fim,int p,int a,int b){

	if(p == 0) return 0;
	if(cont >= 8*maxn) exit(0);

	refresh(init,fim,p);

	if(init > b || fim < a) return 0;

	if(init >= a && fim <= b) 
		return T[p];

	int mid = ((long long)init+fim)/2;
	int ret = query(init,mid,l[p],a,b) + query(mid+1,fim,r[p],a,b);
	T[p] = T[l[p]] + T[r[p]];
	return ret;

}

int X[maxn];

main(){  

        int n;
        scanf("%d",&n);
        
        vector<pii> v;
        
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            X[i] = x;
            v.pb(pii(x,y));
        }    
        
        sort(v.begin(), v.end(), cmp);           
            
        int q;
        scanf("%d",&q);
        
        for(int i=0;i<q;i++){
            int x,y;
            scanf("%d%d",&x,&y), x--, y--;
            Q[i] = Query(x,y,i);
        }
        
        sort(Q,Q+q);
        
        int ptr = 0;
        int maxl = 2000002000;
       
        
        for(int i=0;i<q;i++){
            
            while(ptr < n && v[ptr].first >= X[Q[i].x]){
               update(0,maxl,1,v[ptr].first,v[ptr].first+v[ptr].second-1);
                debug("update %d~%d\n",v[ptr].first,v[ptr].first+v[ptr].second-1);
                ptr++;
            } 
            
            int a = query(0,maxl,1,X[Q[i].x],X[Q[i].y]-1); 
            ans[Q[i].idx] = X[Q[i].y] - X[Q[i].x] - a;
            debug("query %d~%d = %d\n",X[Q[i].x],X[Q[i].y]-1,a);
            
        }
        
        for(int i=0;i<q;i++)
            printf("%d\n",ans[i]);
            
}