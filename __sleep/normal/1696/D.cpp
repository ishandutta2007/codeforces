#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t, n;
const int N=250005;
int st[2][N][20],p[N];
inline int query(int l,int r,int s){
    int len = r-l+1,p=1;
    while((1<<p+1)<len) ++p;
    if(s) return max(st[1][r][p],st[1][l+(1<<p)-1][p]);
    else return min(st[0][r][p],st[0][l+(1<<p)-1][p]);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans=0;
        for (int i = 1; i <= n;i++){
            scanf("%d", st[0][i]);
            p[st[0][i][0]]=i;
            st[1][i][0]=st[0][i][0];
            for(int p=1;(1<<p)<=i;++p){
                st[0][i][p]=min(st[0][i][p-1],st[0][i-(1<<p-1)][p-1]);
                st[1][i][p]=max(st[1][i][p-1],st[1][i-(1<<p-1)][p-1]);
            }
        }
        for(int l=1;l<n;){
            int ll=l+1,rr=n+1,mid;
            while(rr-ll>1){
                mid=(ll+rr)>>1;
                int mn=query(l,mid,0);
                int mx=query(l,mid,1);
                if(!(mn==st[0][l][0]||mx==st[0][l][0])) rr=mid;
                else ll=mid;
                // printf("%d %d %d %d\n",mn,mx,ll,rr);
            }
            // return 0;
            int mn=query(l,ll,0);
            int mx=query(l,ll,1);
            // printf("# %d %d %d %d\n",l,mx,mn,st[0][l][0]);
            l=p[mx^mn^st[0][l][0]];
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
5
1 4 2 3 5
*/