#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 131072
using namespace std;
int n, Q, Dep[101000], par[101000][20], Num[101000], Ed[101000], cnt, m, reNum[101000];
int IT[SZ+SZ+2], w[101000], D[101000][2];
vector<int>E[101000], F[101000];
void DFS(int a, int pp){
    int i;
    par[a][0]= pp;
    Num[a] = ++cnt;
    reNum[cnt] = a;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            Dep[E[a][i]]=Dep[a]+1;
            DFS(E[a][i],a);
        }
    }
    Ed[a] = cnt;
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1){
            a = par[a][i];
        }
        i++;d>>=1;
    }
    for(i=16;i>=0;i--){
        if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    }
    if(a!=b)a = par[a][0];
    return a;
}
bool v[101000], Leaf[101000];
void Ins(int num, int be, int ed){
    be+=SZ,ed+=SZ;
    while(be<=ed){
        IT[be] = max(IT[be], num);
        IT[ed] = max(IT[ed], num);
        be=(be+1)>>1;
        ed=(ed-1)>>1;
    }
}
int Get(int a){
    a += SZ;
    int r = 0;
    while(a){
        r = max(r, IT[a]);
        a>>=1;
    }
    return r;
}
void Del(int b, int e){
    b+=SZ,e+=SZ;
    while(b<=e){
        IT[b]=IT[e]=0;
        b=(b+1)>>1;
        e=(e-1)>>1;
    }
}
void DP(int a){
    int i, x, ck, s, s2, mm;
    D[a][0]=D[a][1]=-1;
    if(F[a].size()==0){
        D[a][1]=0;
        D[a][0]=1;
        return;
    }
    for(i=0;i<F[a].size();i++){
        DP(F[a][i]);
    }
    if(Leaf[a]){
        s = 0, ck = 0;
        for(i=0;i<F[a].size();i++){
            x = F[a][i];
            s += D[x][0];
        }
        D[a][1] = s;
        D[a][0] = s+1;
        return;
    }
    s = 0, s2 = 0, mm = 0;
    for(i=0;i<F[a].size();i++){
        x = F[a][i];
        s += D[x][0];
        s2 += D[x][1];
        mm = max(mm, D[x][0]-D[x][1]);
    }
    D[a][0] = min(s, s2+1);
    D[a][1] = min(D[a][0],s-mm);
}
int main(){
    int a, b, i, j, t, Root, Mn;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1, 0);
    for(i=0;i<16;i++){
        for(j=1;j<=n;j++){
            par[j][i+1] = par[par[j][i]][i];
        }
    }
    int ck;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d",&w[i]);
            w[i] = Num[w[i]];
        }
        sort(w+1,w+m+1);
        for(i=1;i<=m;i++){
            w[i] = reNum[w[i]];
            v[w[i]]=true;
            Leaf[w[i]]=true;
        }
        ck = 0;
        for(i=1;i<=m;i++){
            if(Leaf[par[w[i]][0]])ck = 1;
        }
        if(ck){
            for(i=1;i<=m;i++){
                v[w[i]]=false;
                Leaf[w[i]]=false;
            }
            printf("-1\n");
            continue;
        }
        t = m;
        for(i=1;i<m;i++){
            a = LCA(w[i],w[i+1]);
            if(!v[a]){
                w[++t] = a;
                v[a]=true;
            }
        }
        m = t;
        Mn = n+1;
        for(i=1;i<=m;i++){
            v[w[i]]=false;
            if(Mn > Num[w[i]]){
                Mn = Num[w[i]];
                Root = w[i];
            }
            Ins(Num[w[i]], Num[w[i]]+1,Ed[w[i]]);
        }
        for(i=1;i<=m;i++){
            if(Root != w[i]){
                a = reNum[Get(Num[w[i]])];
                F[a].push_back(w[i]);
            }
        }
        for(i=1;i<=m;i++){
            Del(Num[w[i]]+1,Ed[w[i]]);
        }
        DP(Root);
        printf("%d\n",D[Root][1]);
        for(i=1;i<=m;i++){
            Leaf[w[i]] = false;
            F[w[i]].clear();
        }
    }
}