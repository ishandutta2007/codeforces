#include <bits/stdc++.h>
#define maxn 200200
#define ll long long
#define pb push_back
#define debug 
#define pii pair<int,int>
using namespace std;

ll mini[8*maxn];
int occ[8*maxn];
ll lazy[8*maxn];

ll v[maxn];

void refresh(int ini,int fim,int p){
    
    mini[p] -= lazy[p];
    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
    lazy[p] = 0;
    
}

void build(int ini,int fim,int p){
    
    if(ini == fim){
        mini[p] = v[ini];
        occ[p] = ini;
        return;
    }
    
    int mid = (ini+fim)/2;
    build(ini,mid,2*p);
    build(mid+1,fim,2*p+1);
    
    if(mini[2*p] < mini[2*p+1]){
        mini[p] = mini[2*p];
        occ[p] = occ[2*p];
    }
    else {
        mini[p] = mini[2*p+1];
        occ[p] = occ[2*p+1];
    }
    debug("node %d..%d mini %lld\n",ini,fim,mini[p]);
}

void update(int ini,int fim,int p,int l,int r,ll dec){
       refresh(ini,fim,p);
    if(l > fim || r < ini) return;

    if(l <= ini && r >= fim){
        debug("oi %d..%d\n",ini,fim);
        lazy[p] += dec;
        refresh(ini,fim,p);
        return;
        
    }
    int mid = (ini+fim)/2;
    update(ini,mid,2*p,l,r,dec);
    update(mid+1,fim,2*p+1,l,r,dec);

    if(mini[2*p] < mini[2*p+1]){
        mini[p] = mini[2*p];
        occ[p] = occ[2*p];
    }
    else {
        mini[p] = mini[2*p+1];
        occ[p] = occ[2*p+1];
    }
    debug("mini[%d..%d] := %lld (%lld %lld)\n",ini,fim,mini[p],mini[2*p],mini[2*p+1]);
    
}

int ans[maxn];

int main(){
    
    int n;
    scanf("%d",&n);;
    for(int i=0;i<n;i++)
        scanf("%lld",v+i);
    build(0,n-1,1);
    
    for(int i=1;i<=n;i++){
        
        debug("root %d %d\n",mini[1],occ[1]);
        int id = occ[1];
        debug("dec %d from %d..%d\n",i,id+1,n-1);
        update(0,n-1,1,id+1,n-1,i);
        debug("add inf to %d\n",id);
        update(0,n-1,1,id,id,-(1e12));
        ans[id] = i;
        
    }
    
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    
    
    
}