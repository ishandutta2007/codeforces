#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#define N 200100
#define M 400100
#define Q 500100
#define x first
#define y second
using namespace std;
int cnt[M],tcnt[128],id[2][M],rk[2][M],p;
char s[M];
int *sar,f[N],pos[N],num[M];
int ans[Q],slen[N],pl[N],pr[N];
vector<pair<int,int> > g[M];
inline bool same(int i,int j,int r,int n){
    return i+r<n&&j+r<n&&rk[p][i]==rk[p][j]&&rk[p][i+r]==rk[p][j+r];
}
void suf_ar(int n){
    int i,r,j;
    for(i=0;i<n;i++){
        cnt[s[i]]++;
        rk[p][i]=s[i];
    }
    for(i=1;i<128;i++) cnt[i]+=cnt[i-1];
    memcpy(tcnt,cnt,sizeof(tcnt));
    for(i=n-1;i>=0;i--){
        id[p][--tcnt[s[i]]]=i;
    }
    for(r=1;r<n;r<<=1){
        for(i=n-1;i>=0;i--){
            if(id[p][i]>=r){
                j=id[p][i]-r;
                id[p^1][--cnt[rk[p][j]]]=j;
            }
        }
        for(i=n-r;i<n;i++){
            id[p^1][--cnt[rk[p][i]]]=i;
        }
        rk[p^1][id[p^1][0]]=0;
        cnt[0]=1;
        for(i=1;i<n;i++){
            if(same(id[p^1][i],id[p^1][i-1],r,n)){
                rk[p^1][id[p^1][i]]=rk[p^1][id[p^1][i-1]];
            }
            else{
                rk[p^1][id[p^1][i]]=rk[p^1][id[p^1][i-1]]+1;
            }
            cnt[rk[p^1][id[p^1][i]]]=i+1;
        }
        p^=1;
        if(rk[p][id[p][n-1]]==n-1) break;
    }
    sar=id[p];
}
void add(int x){
    while(x<N){
        f[x]++;
        x+=x&-x;
    }
}
int sum(int x){
    int r=0;
    while(x){
        r+=f[x];
        x-=x&-x;
    }
    return r;
}
int bs(int l,int r,char c,int len){
    r++;
    while(l+1<r){
        int md=(l+r)>>1;
        if(s[sar[md]+len]<=c) l=md;
        else r=md;
    }
    return l;
}
int main(){
    int n,q,m=0,i,j,l,r,k;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        pos[i]=m;
        scanf("%s",s+m);
        while(s[m]) num[m++]=i;
        slen[i]=m-pos[i];
        s[m++]='$';
    }
    suf_ar(m);
    for(i=1;i<=n;i++){
        pl[i]=-1;
        pr[i]=m-1;
        for(j=0;j<slen[i];j++){
            l=bs(pl[i],pr[i],s[pos[i]+j]-1,j);
            r=bs(pl[i],pr[i],s[pos[i]+j],j);
            pl[i]=l;
            pr[i]=r;
        }
    }
    for(i=1;i<=q;i++){
        scanf("%d%d%d",&l,&r,&k);
        if(pl[k]>=0){
            g[pl[k]].push_back(make_pair(i,l-1));
            g[pl[k]].push_back(make_pair(-i,r));
        }
        if(pr[k]>=0){
            g[pr[k]].push_back(make_pair(i,r));
            g[pr[k]].push_back(make_pair(-i,l-1));
        }
    }
    for(i=0;i<m;i++){
        if(num[sar[i]]) add(num[sar[i]]);
        for(j=0;j<g[i].size();j++){
            if(g[i][j].x<0) ans[-g[i][j].x]-=sum(g[i][j].y);
            else ans[g[i][j].x]+=sum(g[i][j].y);
        }
    }
    for(i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}