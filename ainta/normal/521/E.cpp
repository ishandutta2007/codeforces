#include<stdio.h>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
vector<int>E[201000];
int n, m, Num[201000], cnt, chk, par[201000], TP[201000], cc, reNum[201000];
int LCA(int a, int b){
    while(a!=b){
        if(Num[a]<Num[b])b=par[b];
        else a=par[a];
    }
    return a;
}
void Get(int a, int b){
    TP[cc++]=a;
    while(a!=b){
        a=par[a];
        TP[cc++]=a;
    }
}
void Print2(int t){
    int i;
    printf("%d ",cc);
    if(!t)for(i=0;i<cc;i++)printf("%d ",TP[i]);
    else for(i=cc-1;i>=0;i--)printf("%d ",TP[i]);
    printf("\n");
}
void Print(int a, int b, int c, int d){
    chk=1;
    printf("YES\n");
    int uu=Num[a]<Num[c]?c:a, dd = LCA(b,d);
    cc=0;Get(dd,uu);Print2(0);
    cc=0;Get(uu, a);Get(b,dd);Print2(1);
    cc=0;Get(uu, c);Get(d,dd);Print2(1);
}
pii DFS(int a, int pp){
    par[a]=pp;
    Num[a]=++cnt;
    reNum[cnt]=a;
    int i, ck = 0, res[2][2];
    pii r = pii(cnt,0), t;
    for(i=0;i<E[a].size();i++){
        if(chk)return pii(0,0);
        if(E[a][i]==pp)continue;
        if(Num[E[a][i]]){
            if(Num[E[a][i]] < Num[a]){
                r=min(r,pii(Num[E[a][i]],Num[a]));
                res[ck][0]=E[a][i],res[ck][1]=a;
                ck++;
                if(ck==2)Print(res[0][0],res[0][1],res[1][0],res[1][1]);
            }
            continue;
        }
        t = DFS(E[a][i],a);
        if(chk)return pii(0,0);
        if(t.first < Num[a]){
            res[ck][0]=reNum[t.first],res[ck][1]=reNum[t.second];
            ck++;
            if(ck==2)Print(res[0][0],res[0][1],res[1][0],res[1][1]);
        }
        r=min(r,t);
    }
    return r;
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!Num[i])DFS(i,0);
        if(chk)break;
    }
    if(!chk)printf("NO\n");
}