#include <bits/stdc++.h>
#define maxn 1001000
#define ll long long
#define pb push_back
#define debug 
#define pii pair<int,int>
using namespace std;
#define inf (1100000000)

int T[4*maxn];

void update(int ini,int fim,int p,int pos,int val){
    if(pos < ini || pos > fim) return;
    if(ini == fim){
        T[p] = val;
        return;
    }
    int mid = (ini+fim)/2;
    update(ini,mid,2*p,pos,val);
    update(mid+1,fim,2*p+1,pos,val);
    T[p] = max(T[2*p],T[2*p+1]);
    
}

int qry(int ini,int fim,int p,int l,int r){
    if(l > fim || r < ini) return -inf;
    if(l <= ini && r >= fim)
        return T[p];
    int mid = (ini+fim)/2;
    int a = qry(ini,mid,2*p,l,r);
    int b = qry(mid+1,fim,2*p+1,l,r);
    return max(a,b);
}

ll ans[maxn];
ll acc[maxn];
int foii[maxn];

int main(){
    
    int n,sz;
    scanf("%d%d",&n,&sz);
    
    for(int i=0;i<n;i++){
     
        int t;
        scanf("%d",&t);
        
        int mx = 0;
        
        for(int j=0;j<t;j++){
            int u;
            scanf("%d",&u);
            mx = max(mx,u);
            update(0,t-1,1,j,u);
        }
        
        if(sz > 2*t){
            acc[t] += mx;
            acc[sz-t] -= mx;
        }
        
        for(int j=0;j<t;j++){
            foii[j] = i+1;
            
            int pode0 = 0;
            if(j < sz-t) pode0 = 1;
            int R = j;
            int L = max(0, j - (sz-t));
            debug("j %d qry %d..%d pode0 %d\n",j,L,R,pode0);
            int resp = qry(0,t-1,1,L,R);
            if(pode0) resp = max(resp,0);
            ans[j] += resp;
            debug("+ %d\n\n",resp);
            
        }
        
        for(int j=sz-t;j<sz;j++)
            if(foii[j] != i+1){
                
                int pode0 = 0;
                if(j >= t) pode0 = 1;
                int L = t - (sz-j);
                int R = j;
                if(j >= t) R = t-1;
                debug("j %d qry %d..%d pode0 %d\n",j,L,R,pode0);
                int resp = qry(0,t-1,1,L,R);
                if(pode0) resp = max(resp,0);
                ans[j] += resp;
                 debug("+ %d\n\n",resp);
                
            }
        
    
    }
    
    for(int i=0;i<sz;i++){
        printf("%lld ",ans[i]+acc[i]);
        acc[i+1] += acc[i];
    }
}