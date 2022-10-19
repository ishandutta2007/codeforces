#include <bits/stdc++.h>
#define maxn 200200
#define inf 1e8
using namespace std;

struct node {
    int v[32];
};

node null;
int k;

node mg(node a,node b){
    node r;
    for(int i=0;i<32;i++)
        r.v[i] = max(a.v[i],b.v[i]);
    return r;
}

node T[4*maxn];
int dim[5][maxn];

void upd(int ini,int fim,int p,int pos){
    if(ini > pos || fim < pos) return;
    if(ini == fim){
        for(int i=0;i<(1<<k);i++){
            int s = 0;
            for(int j=0;j<k;j++){
                if(i & (1<<j))
                    s += dim[j][pos];
                else
                    s -= dim[j][pos];
            }
            T[p].v[i] = s;
        }
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos);
    upd(mid+1,fim,2*p+1,pos);
    T[p] = mg(T[2*p],T[2*p+1]);
}

node qry(int ini,int fim,int p,int l,int r){
    if(ini > r || fim < l) return null;
    if(ini >= l && fim <= r) return T[p];
    int mid = (ini+fim)/2;
    node a = qry(ini,mid,2*p,l,r);
    node b = qry(mid+1,fim,2*p+1,l,r);
    return mg(a,b);
}

int main() {
    int n;
    scanf("%d%d",&n,&k);
    for(int i=0;i<(1<<k);i++)
        null.v[i] = -inf;
        
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            scanf("%d",&dim[j][i]);
            
    for(int i=0;i<n;i++)
        upd(0,n-1,1,i);
        
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t == 1){
            int id;
            scanf("%d",&id), id--;
            for(int i=0;i<k;i++)
                scanf("%d",&dim[i][id]);
            upd(0,n-1,1,id);
        }
        else {
            int l,r;
            scanf("%d%d",&l,&r), l--, r--;
            node a = qry(0,n-1,1,l,r);
            int fl = (1<<k)-1;
            int ans = 0;
            for(int i=0;i<(1<<k);i++)
                ans = max(ans,a.v[i]+a.v[i^fl]);
            printf("%d\n",ans);
        }
    }
}