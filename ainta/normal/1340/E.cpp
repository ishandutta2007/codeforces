#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
int n, m, D[5010][5010], Q[5010];
vector<int>E[5010];
void BFS(int a){
    int i, head=0,tail=0;
    for(i=1;i<=n;i++)D[a][i]=1e9;
    D[a][a]=0;Q[++tail]=a;
    while(head<tail){
        int x = Q[++head];
        for(auto &y:E[x]){
            if(D[a][y]>D[a][x]+1){
                D[a][y]=D[a][x]+1;
                Q[++tail]=y;
            }
        }
    }
    
}
void Go(int &a, int b){
    int cur = a;
    for(auto &x : E[a]){
        if(D[b][x]<D[b][cur])cur=x;
    }
    a=cur;
}
int Get(int a, int b){
    int cur = a;
    for(auto &x : E[a]){
        if(D[b][x]<D[b][cur])cur=x;
    }
    return D[b][cur];
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        BFS(i);
    }
    int x = 1, y = 1, z = 1;
    for(i=1;i<=n;i++){
        if(D[x][y]<D[x][i])y=i;
    }
    for(i=1;i<=n;i++){
        if(D[x][z]+D[y][z]<D[x][i]+D[y][i])z=i;
    }
    while(1){
        printf("%d %d %d\n",x,y,z);
        fflush(stdout);
        int a;
        scanf("%d",&a);
        if(a==x||a==y||a==z){
            return 0;
        }
        if(D[a][x]==1||D[a][y]==1||D[a][z]==1){
            if(D[a][x]==1)x=a;
            if(D[a][y]==1)y=a;
            if(D[a][z]==1)z=a;
            printf("%d %d %d\n",x,y,z);
            fflush(stdout);
            return 0;
        }
        if(E[a].size()==1){
            Go(x,E[a][0]);
            Go(y,E[a][0]);
            Go(z,E[a][0]);
        }
        else if(E[a].size()==2){
            int i, M = 1e9, pv=-1;
            for(i=0;i<8;i++){
                if(i==0||i==7)continue;
                int zz = Get(x,E[a][i&1]) + Get(y,E[a][(i&2)>>1]) + Get(z,E[a][(i&4)>>2]);
                if(M>zz)M=zz,pv=i;
            }
            Go(x,E[a][pv&1]);
            Go(y,E[a][(pv&2)>>1]);
            Go(z,E[a][(pv&4)>>2]);
        }
        else if(E[a].size()==3){
            int TP[3]={0,1,2}, M = 1e9, PP[3];
            do{
                int zz = Get(x,E[a][TP[0]])+Get(y,E[a][TP[1]])+Get(z,E[a][TP[2]]);
                if(M>zz){
                    M=zz;for(i=0;i<3;i++)PP[i]=TP[i];
                }
            }while(next_permutation(TP,TP+3));
            Go(x,E[a][PP[0]]);
            Go(y,E[a][PP[1]]);
            Go(z,E[a][PP[2]]);
        }
    }
}