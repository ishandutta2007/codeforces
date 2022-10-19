#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define debug 
#define inf (1e6)
using namespace std;
 
int a[maxn];
int b[maxn];
 
int T[4*maxn];

void upd(int ini,int fim,int p,int pos,int val){
    if(pos < ini || pos > fim) return;
    if(ini == fim){
        T[p] = val;
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos,val);
    upd(mid+1,fim,2*p+1,pos,val);
    T[p] = min(T[2*p],T[2*p+1]);
}

int qry(int ini,int fim,int p,int l,int r){
    if(l > fim || r < ini) return inf;
    if(l <= ini && r >= fim) return T[p];
    int mid = (ini+fim)/2;
    return min( qry(ini,mid,2*p,l,r), qry(mid+1,fim,2*p+1,l,r));
}
 
int main(){
    
    int nt;
    scanf("%d",&nt);
    
    while(nt--){
        
        int n;
        scanf("%d",&n);
        
        vector<pii> va, vb;
        
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            va.pb(pii(a[i],i));
        }
        for(int i=0;i<n;i++){
            scanf("%d",b+i);
            vb.pb(pii(b[i],i));
        }
        
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        
        int ok = 1;
        
        for(int i=0;i<n;i++)
            upd(0,n-1,1,i,n+1);
            
        for(int i=0;i<n;i++){
            int pos = va[i].second;
            int to = vb[i].second;
            if(va[i].first != vb[i].first) ok = 0;
            if(qry(0,n-1,1,to+1,n-1) < pos) ok = 0;
            upd(0,n-1,1,to,pos);
        }
        
        puts(ok?"YES":"NO");
        
    }
    
}