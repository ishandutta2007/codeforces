#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=600005;
char s[N];
vector<int> ans[N];
int sum[N],base,l[N],r[N],rk[N],val[N<<1];
inline bool cmp(int x,int y){
    return r[x]<r[y];
}
inline void work(int nl,int nr,int id){
    if(nl==nr){ans[id].push_back(nl); return;}
    int tmp=sum[nr]+sum[nl-1];
    // printf("%d %d %d\n",nl,nr,tmp);
    ans[id].push_back(val[tmp]);
    // printf("%d ",val[tmp]);
}
int main(){
    int t,n,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%s",&n,&q,s+1);
        sum[0]=0; base=1e9;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+(i&1?-1:1)*(s[i]=='+'?1:-1);
            if(base>sum[i]) base=sum[i];
        }
        sum[0]-=base;
        for(int i=1;i<=q;i++){
            rk[i]=i;
            ans[i].clear();
            scanf("%d%d",l+i,r+i);
        }
        sort(rk+1,rk+1+q,cmp);
        int now=0,id;
        for(int i=1;i<=q;i++){
            id=rk[i];
            while(now<r[id]){
                ++now;
                sum[now]-=base;
                val[sum[now]+sum[now-1]]=now;
            }
            if((r[id]^l[id]^1)&1){
                work(l[id],r[id],id);
            }
            else if(sum[r[id]]-sum[l[id]-1]==0) continue;
            else{
                work(l[id],r[id]-1,id);
                ans[id].push_back(r[id]);
            }
        }
        for(int i=1;i<=q;i++){
            printf("%d\n",(int)ans[i].size());
            for(auto v:ans[i])
                printf("%d ",v);
            if(ans[i].size()) puts("");
        }
    }
    return 0;
}
/*
1
14 1
+--++---+++---
1 14

1
4 1
+-+-
1 3

1
14 1
+--++---+++---
3 10
*/