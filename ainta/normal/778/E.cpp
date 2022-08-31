#include<cstdio>
#include<algorithm>
using namespace std;
char p[1010];
int w[1010], L, n, P[1010][1010], m, Rank[1010], Len[1010];
int D[1010][1010], SS[10], CC[10];
struct A{
    int a, num;
    bool operator<(const A &p)const{
        return a<p.a;
    }
}ord[1010];
int score[10];
void Ins(int a, int pv, int b, int ck){
    int i;
    for(i=0;i<10;i++){
        if(i==0){
            if(!b && Len[a] < pv && L < pv)continue;
        }
        SS[i] += score[(b+i)%10]*ck;
        if(i + b >= 10)CC[i] += ck;
    }
}
int main(){
    int i, j, k;
    scanf("%s",p);
    for(i=0;p[i];i++);
    L = i;
    for(i=0;i<L;i++){
        if(p[L-i-1] == '?') w[i+1] = -1;
        else w[i+1] = p[L-i-1] - '0';
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",p);
        for(j=0;p[j];j++);
        int tt = j;
        for(j=0;j<tt;j++){
            P[i][j+1] = p[tt-j-1]-'0';
        }
        Len[i] = tt;
    }
    for(i=0;i<10;i++)scanf("%d",&score[i]);
    m = 1006;
    for(i=0;i<=m;i++)for(j=0;j<=m;j++)D[i][j] = -1;
    D[0][0] = 0;
    for(i=0;i<m;i++){
        for(j=1;j<=n;j++)ord[j].a = Rank[j] + P[j][i] * 10000, ord[j].num = j;
        sort(ord+1,ord+n+1);
        for(j=1;j<=n;j++)Rank[ord[j].num] = j;
        for(j=0;j<10;j++)CC[j]=SS[j]=0;
        for(j=1;j<=n;j++)Ins(j, i+1, P[j][i+1], 1);
        for(j=0;j<=n;j++){
            if(D[i][j] != -1){
                for(k=0;k<10;k++){
                    if(i+1 == L && k == 0)continue;
                    if(w[i+1]!=-1 && w[i+1]!=k)continue;
                    D[i+1][CC[k]] = max(D[i+1][CC[k]], D[i][j] + SS[k]);
                }
            }
            if(j==n)break;
            int tp = ord[n-j].num;
            Ins(tp, i+1, P[tp][i+1], -1);
            Ins(tp, i+1, P[tp][i+1]+1, 1);
        }
        //for(j=0;j<=n;j++)printf("%d ",D[i+1][j]);
        //printf("\n");
    }
    printf("%d\n",D[m][0]);
}