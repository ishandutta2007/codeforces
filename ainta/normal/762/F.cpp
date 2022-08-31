#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int Num[13][13], H[13][13], n, m, cnt;
long long D[1010][200], Mod = 1000000007, U[200];
vector<int>G[1010], E[13], Ch[13][13], P[200];
vector<pii>L[13];
void DFS1(int a, int pp, int rt){
    int i;
    H[rt][a] = 0;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp)continue;
        Ch[rt][a].push_back(E[a][i]);
        DFS1(E[a][i], a, rt);
        H[rt][a] = max(H[rt][a], H[rt][E[a][i]] + 1);
    }
    L[H[rt][a]].push_back(pii(rt,a));
}
bool Same(pii a, pii b){
    int i, rt1 = a.first, rt2 = b.first, x1 = a.second, x2 = b.second;
    vector<int>P1, P2;
    for(i=0;i<Ch[rt1][x1].size();i++){
        P1.push_back(Num[rt1][Ch[rt1][x1][i]]);
    }
    for(i=0;i<Ch[rt2][x2].size();i++){
        P2.push_back(Num[rt2][Ch[rt2][x2][i]]);
    }
    if(P1.size()!=P2.size())return false;
    if(P1.size()==0)return true;
    sort(P1.begin(),P1.end());
    sort(P2.begin(),P2.end());
    for(i=0;i<P1.size();i++)if(P1[i]!=P2[i])return false;
    return true;
}
long long TP[2048];
void DFS2(int a, int pp){
    int i, j, k, l, x;
    vector<int>C;
    for(i=0;i<G[a].size();i++){
        if(G[a][i]==pp)continue;
        DFS2(G[a][i], a);
        C.push_back(G[a][i]);
    }
    for(i=1;i<=cnt;i++){
        int ct = P[i].size();
        if(C.size() < ct)continue;
        if(P[i].empty()){
            D[a][i]=1;
            continue;
        }
        for(j=0;j<(1<<ct);j++)TP[j]=0;
        TP[0] = 1;
        for(j=0;j<C.size();j++){
            x = C[j];
            for(l=(1<<ct)-1;l>=0;l--){
                if(!TP[l])continue;
                for(k=0;k<ct;k++){
                    if(l&(1<<k))continue;
                    long long t = D[x][P[i][k]];
                    TP[l|(1<<k)] = (TP[l|(1<<k)] + TP[l] * t) % Mod;
                }
            }
        }
        D[a][i] = TP[(1<<ct)-1] * U[i]%Mod;
    }
}
bool v[200];
int Calc(vector<int> &P){
    int i, c = 0, r = 1, j;
    for(i=0;i<P.size();i++){
        c++;
        if(i==P.size()-1 || P[i]!=P[i+1]){
            for(j=1;j<=c;j++)r=r*j;
            c=0;
        }
    }
    return r;
}
long long Pow(long long a, int b){
    long long r = 1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
int main(){
    int i, a, b, j, k;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scanf("%d",&m);
    for(i=1;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=m;i++){
        DFS1(i,0,i);
    }
    for(i=0;i<m;i++){
        for(j=0;j<L[i].size();j++){
            int rt = L[i][j].first, x = L[i][j].second;
            for(k=0;k<j;k++){
                if(Same(L[i][j],L[i][k])){
                    Num[rt][x] = Num[L[i][k].first][L[i][k].second];
                    break;
                }
            }
            if(k==j){
                Num[rt][x] = ++cnt;
                for(k=0;k<Ch[rt][x].size();k++)P[cnt].push_back(Num[rt][Ch[rt][x][k]]);
                if(!P[cnt].empty())sort(P[cnt].begin(),P[cnt].end());
                U[cnt] = Pow(Calc(P[cnt]), Mod-2);
            }
        }
    }
    DFS2(1, 0);
    long long res = 0;
    for(i=1;i<=m;i++){
        if(!v[Num[i][i]]){
            v[Num[i][i]] = true;
            for(j=1;j<=n;j++) res = (res + D[j][Num[i][i]])%Mod;
        }
    }
    printf("%lld\n",res);
}