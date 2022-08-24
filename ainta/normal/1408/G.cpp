#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, w[1510][1510], UF[1510][2], vis[1510], A[1510], Loc[1510], Z[1510][1510];
int Dis[1510][1510], ord[1510][1510], IT[1510][4096], SZ = 2048;
int D[1510][1510], Mod = 998244353;
vector<int>G[1510], U[1510];
struct Edge{
    int a, b, c;
    bool operator <(const Edge &p)const{
        return c<p.c;
    }
};
struct AA{
    int d, num;
    bool operator <(const AA &p)const{
        return d<p.d;
    }
}TP[1510];
vector<Edge>E;
int Find(int a, int ck){
    if(a==UF[a][ck])return a;
    return UF[a][ck]=Find(UF[a][ck],ck);
}
void Merge(int a, int b){
    if(Find(a,0)==Find(b,0))return;
    int x = Find(a,1), y = Find(b,0);
    UF[y][0]=x, UF[x][1]=y;
    G[x].push_back(y);
    G[y].push_back(x);
}
int Max(int a, int b, int e){
    b+=SZ,e+=SZ;
    int r=0;
    while(b<=e){
        r=max(r,max(IT[a][b],IT[a][e]));
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
bool Check(int bb, int ee){
    int i;
    for(i=bb;i<=ee;i++){
        if(Max(i,bb,ee)>ee-bb+1)return false;
    }
    U[bb].push_back(ee);
    return true;
}
void Build(int a){
    int i;
    for(i=1;i<=n;i++)IT[a][i+SZ]=ord[a][i];
    for(i=SZ-1;i>=1;i--){
        IT[a][i]=max(IT[a][i*2],IT[a][i*2+1]);
    }
}
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        UF[i][0]=i;
        UF[i][1]=i;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&w[i][j]);
            if(i<j){
                E.push_back({i,j,w[i][j]});
            }
        }
    }
    sort(E.begin(),E.end());
    for(auto &t : E){
        Merge(t.a, t.b);
    }
    for(i=1;i<=n;i++){
        if(G[i].size()==1){
            int x = i, c = 0;
            while(1){
                vis[x]=1;
                A[++c] = x;
                //printf("%d %d\n",c,x);
                Loc[x]=c;
                int nxt = -1;
                for(auto &y : G[x]){
                    if(!vis[y]){
                        nxt = y;
                        break;
                    }
                }
                if(nxt==-1)break;
                x=nxt;
            }
            break;
        }
    }
    for(i=1;i<=n;i++){
        UF[i][0]=i;
        UF[i][1]=i;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            Dis[i][j]=w[A[i]][A[j]];
        }
        for(j=1;j<=n;j++){
            TP[j]={Dis[i][j],j};
        }
        sort(TP+1,TP+n+1);
        for(j=1;j<=n;j++){
            ord[i][TP[j].num] = j;
        }
        Build(i);
    }
    for(i=1;i<=n;i++)U[i].push_back(i);
    for(auto &t : E){
        int a = Find(t.a,0), b = Find(t.b,0);
        if(a!=b){
            int x = Find(t.a,1), y = Find(t.b,0);
            UF[y][0]=x, UF[x][1]=y;
            int bb = Loc[Find(t.a,0)], ee = Loc[Find(t.b,1)];
            if(bb>ee)swap(bb,ee);
            //printf("%d %d\n",bb,ee);
            Check(bb,ee);
        }
    }
    D[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            for(auto &t : U[i]){
                D[t][j+1]=(D[t][j+1]+D[i-1][j])%Mod;
            }
        }
    }
    for(i=1;i<=n;i++)printf("%d ",D[n][i]);
    puts("");
}