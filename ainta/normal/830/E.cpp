#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, n, m, C[101000], v[101000], Path[101000];
vector<int>E[101000];
void YES(){
    int i;
    printf("YES\n");
    for(i=1;i<=n;i++)printf("%d ",C[i]);
    printf("\n");
}
vector<int>TP, TP3;
int DegSum = 0;
void DFS(int a){
    int i;
    v[a] = 1;
    DegSum += E[a].size();
    TP.push_back(a);
    if(E[a].size() == 3)TP3.push_back(a);
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
}
void Do1(){
    int i;
    for(i=0;i<TP.size();i++)C[TP[i]] = 1;
    YES();
}
void DFS2(int a, int pp){
    Path[a] = pp;
    v[a] = 1;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS2(E[a][i], a);
    }
}
void Do2(){
    int i, a = TP3[0], b = TP3[1];
    for(i=1;i<=n;i++)v[i]=0;
    DFS2(a,0);
    for(i=0;i<E[a].size();i++)C[E[a][i]]=1;
    for(i=0;i<E[b].size();i++)C[E[b][i]]=1;
    while(b){
        C[b] = 2;
        b = Path[b];
    }
    YES();
}
void Do3(){
    int x = TP3[0], i, j;
    for(i=0;i<3;i++){
        int y = E[x][i];
        for(j=0;j<E[y].size();j++){
            C[E[y][j]] = 1;
        }
    }
    for(i=0;i<3;i++)C[E[x][i]] = 2;
    C[x] = 3;
    YES();
}
int D[101000];
void DFS3(int a, int pp){
    D[a] = 1;
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            DFS3(E[a][i],a);
            D[a] = max(D[a],D[E[a][i]] + 1);
        }
    }
}
void Put(int a, int pp, int c, int dd){
    if(c<=0)return;
    C[a] = c;
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)Put(E[a][i],a,c-dd,dd);
    }
}
int main(){
    int i, a, b, j;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            E[i].clear(), C[i] = 0;
            v[i] = 0;
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            E[a].push_back(b);
            E[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(E[i].size()>=4){
                for(j=0;j<4;j++){
                    C[E[i][j]] = 1;
                }
                C[i] = 2;
                
                YES();
                break;
            }
        }
        if(i!=n+1)continue;
        for(i=1;i<=n;i++){
            if(!v[i]){
                DegSum = 0;
                TP.clear();
                TP3.clear();
                DFS(i);
                if(DegSum >= TP.size() * 2){
                    Do1();
                    break;
                }
                if(TP3.size() >= 2){
                    Do2();
                    break;
                }
                if(TP3.size() == 1){
                    int x = TP3[0];
                    DFS3(x,0);
                    int ck = 0, c = 0;
                    vector<int>P;
                    for(j=0;j<3;j++){
                        if(D[E[x][j]] == 1)ck = 1;
                        P.push_back(D[E[x][j]]);
                    }
                    if(ck==0){
                        Do3();
                        break;
                    }
                    sort(P.begin(),P.end());
                    if(P[1] >= 3){
                        C[x] = 4;
                        for(j=0;j<3;j++){
                            if(D[E[x][j]] != 1) Put(E[x][j], x, 3, 1);
                            else Put(E[x][j], x, 2, 1);
                        }
                        YES();
                        break;
                    }
                    if(P[1] == 2 && P[2] >= 5){
                        C[x] = 6;
                        for(j=0;j<3;j++){
                            if(D[E[x][j]] == 1) Put(E[x][j], x, 3, 1);
                            else if(D[E[x][j]] == 2) Put(E[x][j], x, 4, 2);
                            else Put(E[x][j], x, 5, 1);
                        }
                        YES();
                        break;
                    }
                }
            }
        }
        if(i == n+1){
            printf("NO\n");
        }
    }
}