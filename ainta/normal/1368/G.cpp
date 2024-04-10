#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
#define pii pair<int,int>
using namespace std;
int n, m, Bef[201000], Deg[201000], Q[201000], vis[201000], RR[201000], Ed[201000];
char p[201000];
long long res;
vector<pii>U;
vector<vector<char>>V;
vector<int>E[201000];
int NNum(int a, int b){
    return a*m+b;
}
void Add_Edge(int bx, int by, int ex, int ey){
    Deg[NNum(bx,by)]++;
    E[NNum(bx,by)].push_back(NNum(ex,ey));
    Bef[NNum(ex,ey)]=NNum(bx,by);
}
void Del(int a, int b){
    for(int i=0;i<E[a].size();i++){
        if(E[a][i]==b){
            swap(E[a][i],E[a][E[a].size()-1]);
            E[a].pop_back();
            return;
        }
    }
}
int cnt, Num[201000];
void DFS(int a){
    Num[a]=++cnt;
    for(auto &x : E[a]){
        DFS(x);
    }
    Ed[a]=cnt;
}
struct SegTree{
    int Mn[SZ+SZ], MC[SZ+SZ], K[SZ+SZ];
    void UDT(int nd){
        MC[nd]=0;
        Mn[nd]=min(Mn[nd*2],Mn[nd*2+1]);
        if(Mn[nd]==Mn[nd*2])MC[nd]+=MC[nd*2];
        if(Mn[nd]==Mn[nd*2+1])MC[nd]+=MC[nd*2+1];
    }
    void init(int nd, int b, int e){
        K[nd]=0;
        if(b==e){
            Mn[nd]=0;
            MC[nd]=1;
            return;
        }
        int m = (b+e)>>1;
        init(nd*2,b,m);
        init(nd*2+1,m+1,e);
        UDT(nd);
    }
    void Add2(int nd, int x){
        Mn[nd]+=x;
        K[nd]+=x;
    }
    void Spread(int nd){
        Add2(nd*2,K[nd]);
        Add2(nd*2+1,K[nd]);
        K[nd]=0;
    }
    void Add(int nd, int b, int e, int s, int l, int x){
        if(s<=b&&e<=l){
            Add2(nd,x);
            return;
        }
        Spread(nd);
        int m = (b+e)>>1;
        if(s<=m)Add(nd*2,b,m,s,l,x);
        if(l>m)Add(nd*2+1,m+1,e,s,l,x);
        UDT(nd);
    }
}IT;
struct Seg{
    int b, e, ck;
};
vector<Seg>Z[201000];
void Color(int bx, int ex, int by, int ey){
    Z[bx].push_back({by,ey,1});
    Z[ex+1].push_back({by,ey,-1});
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    V.resize(n+2);
    for(i=0;i<=n+1;i++){
        V[i].resize(m+2);
    }
    for(i=0;i<n;i++){
        scanf("%s",p);
        for(j=0;j<m;j++)V[i][j]=p[j];
    }
    for(i=0;i<n*m;i++)Bef[i]=-1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(V[i][j]=='U'){
                U.push_back({NNum(i,j),NNum(i+1,j)});
            }
            if(V[i][j]=='L'){
                U.push_back({NNum(i,j),NNum(i,j+1)});
            }
            if(V[i][j]=='U' && i!=0){
                Add_Edge(i-1,j,i+1,j);
            }
            if(V[i][j]=='D' && i!=n-1){
                Add_Edge(i+1,j,i-1,j);
            }
            if(V[i][j]=='L' && j!=0){
                Add_Edge(i,j-1,i,j+1);
            }
            if(V[i][j]=='R' && j!=m-1){
                Add_Edge(i,j+1,i,j-1);
            }
        }
    }
    for(i=0;i<U.size();i++){
        int t=U[i].first;
        if((t/m+t%m)&1)swap(U[i].first,U[i].second);
    }
    int head=0,tail=0;
    for(i=0;i<n*m;i++){
        if(!Deg[i])Q[++tail]=i;
    }
    while(head < tail){
        int x = Q[++head];
        if(Bef[x]!=-1){
            Deg[Bef[x]]--;
            if(!Deg[Bef[x]]){
                Q[++tail]=Bef[x];
            }
        }
    }
    for(i=0;i<n*m;i++)RR[i]=i;
    for(i=0;i<n*m;i++){
        if(Deg[i] && !vis[i]){
            int t = i;
            while(!vis[t]){
                vis[t]=1;
                t=Bef[t];
                RR[t]=i;
            }
            Del(Bef[i],i);
            Bef[i] = -1;
        }
    }
    for(i=0;i<n*m;i++){
        if(Bef[i]==-1){
            DFS(i);
        }
    }
    for(auto &t : U){
        int a = RR[t.first], b = RR[t.second];
        Color(Num[a],Ed[a],Num[b],Ed[b]);
    }
    IT.init(1,1,SZ);
    for(i=1;i<=n*m;i++){
        for(auto &t : Z[i]){
            IT.Add(1, 1, SZ, t.b,t.e,t.ck);
        }
        res+=SZ-IT.MC[1];
    }
    printf("%lld\n",res);
}