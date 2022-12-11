#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m,k;
int x[200005],y[200005];
vector<int> nx[200005],ny[200005];
int main(){
    scanf("%d",&t);
    while(t--){
        int px,py,ix,iy;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",x+i),nx[i].clear();
        for(int i=1;i<=m;i++)
            scanf("%d",y+i),ny[i].clear();
        for(int i=1;i<=k;i++){
            scanf("%d%d",&px,&py);
            ix=lower_bound(x+1,x+n+1,px)-x;
            iy=lower_bound(y+1,y+m+1,py)-y;
            if(x[ix]!=px) nx[ix].push_back(py);
            if(y[iy]!=py) ny[iy].push_back(px);
        }
        // puts("------------");
        // for(int i=0;i<nx[4].size();i++)
        //     printf("%d ",nx[4][i]);
        // puts("");
        long long ans=0;
        for(int i=1;i<=n;i++){
            auto &v=nx[i];
            sort(v.begin(),v.end());
            for(int l=0,r;l<(int)v.size();l=r+1){
                for(r=l;r+1<(int)v.size()&&v[l]==v[r+1];++r);
                ans+=(v.size()-(r-l+1ll))*(r-l+1);
                // printf("x: %d %d %d %lld\n",i,r-l+1,(int)v.size(),ans);
            }
        }
        for(int i=1;i<=m;i++){
            auto &v=ny[i];
            sort(v.begin(),v.end());
            for(int l=0,r;l<(int)v.size();l=r+1){
                for(r=l;r+1<(int)v.size()&&v[l]==v[r+1];++r);
                ans+=(v.size()-(r-l+1ll))*(r-l+1);
                // printf("y: %d %d %lld\n",i,r-l+1,ans);
            }
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}