#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[60][60];
vector<int>E[60], L[60];
int n, m, st, w[60][60], CC[60];
void Calc(int a, int c){
    int j;
    int b = 0, e = 1e9, mid, r = 0;
    while(b<=e){
        mid = (b+e)>>1;
        int s = 0, chk = 0;
        for(j=1;j<=n;j++){
            if(E[j].size()==1 && j!=a){
                if(mid >= w[a][j]){
                    int t = lower_bound(D[j],D[j]+c,mid-w[a][j]+1)-D[j];
                    s += c - t;
                }
                else{
                    chk = 1;
                }
            }
        }
        if(chk || s >= c){
            b = mid + 1;
        }
        else r = mid, e = mid - 1;
    }
    D[a][c] = r;
}
vector<int>TT;
int SS;
void DFS(int a, int pp){
    int i, ck = 0;
    SS += CC[a];
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)DFS(E[a][i],a), ck = 1;
    }
    if(!ck){
        TT.push_back(a);
    }
}
int Gap(vector<int> &T, int c){
    int j;
    int b = 0, e = 1e9, mid, r = 0;
    while(b<=e){
        mid = (b+e)>>1;
        int s = 0, chk = 0;
        for(j=0;j<T.size();j++){
            int x = T[j];
            if(mid >= w[st][x]){
                int t = lower_bound(D[x],D[x]+m,mid-w[st][x]+1)-D[x];
                s += m - t;
            }
            else{
                chk = 1;
            }
        }
        if(chk || s >= c){
            b = mid + 1;
        }
        else r = mid, e = mid - 1;
    }
    return r;
}
int main(){
    int i, j, a, b, c, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)w[i][j]=1e9;
        w[i][i]=0;
    }
    for(i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back(b);
        E[b].push_back(a);
        L[a].push_back(c);
        L[b].push_back(c);
        w[a][b]=w[b][a]=c;
    }
    for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
    if(n==1){
        printf("0\n");
        return 0;
    }
    scanf("%d%d",&st,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&a);
        CC[a]++;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(E[j].size()==1){
                Calc(j,i);
            }
        }
    }
    int res = 1e9;
    for(i=0;i<E[st].size();i++){
        TT.clear();
        SS = 0;
        DFS(E[st][i],st);
        if(!SS)continue;
        res = min(res, Gap(TT,SS));
    }
    printf("%d\n",res);
}