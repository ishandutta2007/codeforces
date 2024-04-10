#include<stdio.h>
#include<algorithm>
#define SZ 262144
using namespace std;
struct Tree{
    int w[5][5];
}IT[SZ+SZ];
int n, Q;
char p[201000], q[5] = "2016";
Tree Merge(Tree c1, Tree c2){
    int i, j, k;
    Tree tp;
    for(i=0;i<5;i++){
        for(j=i;j<5;j++)tp.w[i][j] = -1;
        for(j=i;j<5;j++){
            if(c1.w[i][j]==-1)continue;
            int t = c1.w[i][j];
            for(k=j;k<5;k++){
                if(c2.w[j][k]==-1)continue;
                if(tp.w[i][k]==-1 || tp.w[i][k] > c2.w[j][k] + t)tp.w[i][k] = c2.w[j][k] + t;
            }
        }
    }
    return tp;
}
void init(int nd, int b, int e){
    if(b==e){
        int i, j;
        for(i=0;i<5;i++){
            for(j=i+1;j<5;j++){
                IT[nd].w[i][j] = -1;
            }
            IT[nd].w[i][i] = 0;
            if(q[i] == p[b]){
                IT[nd].w[i][i] = 1;
                IT[nd].w[i][i+1] = 0;
            }
        }
        return;
    }
    int m = (b+e)>>1;
    init(nd*2,b,m);
    init(nd*2+1,m+1,e);
    IT[nd] = Merge(IT[nd*2],IT[nd*2+1]);
}
Tree Get(int nd, int b, int e, int s, int l){
    if(b==s && e==l)return IT[nd];
    Tree ret, tp;
    int m = (b+e)>>1;
    if(s <= m){
        ret = Get(nd*2,b,m,s,min(m,l));
    }
    if(l > m){
        tp = Get(nd*2+1,m+1,e,max(m+1,s),l);
        if(s<=m)ret=Merge(ret,tp);
        else ret = tp;
    }
    return ret;
}
int P[201000], S[201000];
int main(){
    int i, pv = -1, b, e, x;
    Tree tp;
    scanf("%d%d",&n,&Q);
    scanf("%s",p+1);
    init(1,1,n);
    for(i=1;i<=n;i++){
        if(p[i]=='7')pv=i;
        P[i] = pv;
        S[i]=S[i-1];
        if(p[i]=='6')S[i]++;
    }
    while(Q--){
        scanf("%d%d",&b,&e);
        x = P[e];
        if(x < b){
            printf("-1\n");
            continue;
        }
        tp = Get(1,1,n,b,x);
        if(tp.w[0][3]==-1){
            printf("-1\n");
        }
        else{
            printf("%d\n",tp.w[0][3] + S[e] - S[x]);
        }
    }
}