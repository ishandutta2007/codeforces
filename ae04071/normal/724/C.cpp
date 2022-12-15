#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

lli ans[100001];
pii arr[100001];
int n,m,k;
set<pii> pos,neg;

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++) {
        int a,b;
        scanf("%d%d",&b,&a);
        pos.insert({-a+b, i});
        neg.insert({a+b, i});
        arr[i] = {a,b};
    }
    
    memset(ans,-1,sizeof(ans));
    
    int cy=0,cx=0,dy=1,dx=1;
    lli ti=0;
    do {
        int ny=(dy==1 ? n : 0), nx = (dx==1 ? m : 0);
        
        if(dy*dx>0) {
            int l = cy-cx;
            auto it = pos.lower_bound({l,0});
            while(it!=pos.end() && it->fi==l) {
                if(ans[it->se]==-1) ans[it->se]=ti+abs(cy-arr[it->se].se);
                it = pos.erase(it);
            }
        } else {
            int l = cy+cx;
            auto it = neg.lower_bound({l,0});
            while(it!=neg.end() && it->fi==l) {
                if(ans[it->se]==-1) ans[it->se]=ti+abs(cy-arr[it->se].se);
                it = neg.erase(it);
            }
        }
        ti += min(abs(ny-cy),abs(nx-cx));
        
        if(abs(ny-cy) < abs(nx-cx)) {
            cx += abs(ny-cy)*dx;
            cy = ny;
            dy*=-1;
        } else{
            cy += abs(nx-cx)*dy;
            cx = nx;
            dx*=-1;
        }
    }while( !(cy==0 && cx==0) && !(cy==n && cx==0) && !(cy==0 && cx==m) && !(cy==n && cx==m));
    for(int i=0;i<k;i++) printf("%lld\n",ans[i]);
    
    return 0;
}