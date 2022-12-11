#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005;
int t,n,k,p,val[N],rk[N];
vector<int> a[N];
inline bool judge(int x){
    for(int i=1;i<=n;i++){
        if(x>=val[rk[i]]) x+=a[rk[i]].size();
        else return false;
    }
    return true;
}
inline bool cmp(int x,int y){
    return val[x]<val[y];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            a[i].clear();
            while(k--){
                scanf("%d",&p);
                a[i].push_back(p);
            }
            val[i]=0;
            for(int j=0;j<a[i].size();j++)
                val[i]=max(val[i],a[i][j]-j+1);
            rk[i]=i;
        }
        sort(rk+1,rk+n+1,cmp);
        int l=0,r=1e9+1,mid;
        while(r-l>1){
            mid=(r+l)>>1;
            if(judge(mid)) r=mid;
            else l=mid;
        }    
        printf("%d\n",r);
    }
    return 0;
}