#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

#define N_ 301000
#define pii pair<int,int>

using namespace std;


class Dumae{
public:
    int n, m, K, be[N_], ed[N_], Q[N_], head, tail, DegE[N_], DegF[N_], Res[N_], inp[N_];
    int RRes[N_];
    vector<int>E[N_], F[N_], G[N_];
    void Do(vector<pii>Ed, vector<pii>Ran) {
        int i, a, b;
        n = Ran.size();
        m = Ed.size();
        for(i=1;i<=n;i++){
            be[i]=Ran[i-1].first, ed[i]=Ran[i-1].second;
            //printf("%d %d\n",be[i],ed[i]);
        }
        for (i = 0; i < m; i++) {
            a=Ed[i].first, b=Ed[i].second;
            //printf("%d %d\n",a,b);
            E[a].push_back(b);
            F[b].push_back(a);
            DegE[b]++;
            DegF[a]++;
        }
        for (i = 1; i <= n; i++)if (!DegE[i])Q[++tail] = i;
        while (head < tail) {
            int x = Q[++head];
            for (auto &y : E[x]) {
                be[y] = max(be[y], be[x] + 1);
                DegE[y]--;
                if (!DegE[y])Q[++tail] = y;
            }
        }
        if (tail != n) {
            printf("-1\n");
            return;
        }
        head = tail = 0;
        for (i = 1; i <= n; i++)if (!DegF[i])Q[++tail] = i;
        while (head < tail) {
            int x = Q[++head];
            for (auto &y : F[x]) {
                ed[y] = min(ed[y], ed[x] - 1);
                DegF[y]--;
                if (!DegF[y])Q[++tail] = y;
            }
        }
        for (i = 1; i <= n; i++){
            if (be[i] > ed[i]) {
                printf("-1\n");
                return;
            }
            G[be[i]].push_back(i);
        }
        priority_queue<pii>PQ;
        for (i = 1; i <= n; i++) {
            for (auto &tp : G[i]) {
                PQ.push({-ed[tp], tp});
            }
            if (PQ.empty()) {
                printf("-1\n");
                return;
            }
            int x = PQ.top().second;
            PQ.pop();
            if (ed[x] < i) {
                printf("-1\n");
                return;
            }
            Res[x] = i;
        }
        for (i = 1; i <= n; i++)RRes[Res[i]] = i;
        //for (i = 1; i <= n; i++)printf("%d\n", RRes[i]);
    }
}DD;

int n, m, w[300][300], X[300], Y[300], C[101000], R[300][300], vis[101000];
int A[300], B[300];
vector<int>E[101000];
struct point{
    int x, y, c;
    bool operator <(const point &p)const{
        return c<p.c;
    }
};
int Num(int x, int y){
    return (x-1)*m+y;
}
void Solve(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&w[i][j]);
            X[i]=max(X[i],w[i][j]);
            Y[j]=max(Y[j],w[i][j]);
        }
    }
    for(i=1;i<=n;i++)C[X[i]]|=1;
    for(i=1;i<=m;i++)C[Y[i]]|=2;
    int cnt = 0;
    for(i=1;i<=n*m;i++){
        if(C[i]==3){
            vis[i]=1;
            cnt++;
            R[cnt][cnt]=i;
            A[cnt]=B[cnt]=i;
        }
    }
    int cx=cnt, cy = cnt;
    for(i=n*m;i>=1;i--){
        if(C[i]==1){
            cx++;
            R[cx][cnt]=i;
            vis[i]=1;
            A[cx]=i;
        }
        if(C[i]==2){
            cy++;
            R[cnt][cy]=i;
            vis[i]=1;
            B[cy]=i;
        }
    }
    for(i=1;i<cnt;i++){
        for(j=i;j<m;j++){
            E[Num(i,j)].push_back(Num(i,j+1));
        }
        for(j=i;j<n;j++){
            E[Num(j,i)].push_back(Num(j+1,i));
        }
        for(j=i+1;j<=m;j++){
            E[Num(i+1,j)].push_back(Num(i,j));
        }
        for(j=i+1;j<=n;j++){
            E[Num(j,i+1)].push_back(Num(j,i));
        }
    }
    for(i=cnt;i<=n;i++){
        for(j=cnt;j<=m;j++){
            if(i!=n)E[Num(i,j)].push_back(Num(i+1,j));
            if(j!=m)E[Num(i,j)].push_back(Num(i,j+1));
        }
    }
    int pv=0;
    vector<pii>Ran;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(R[i][j])Ran.push_back({R[i][j],R[i][j]});
            else Ran.push_back({1,n*m});
        }
    }
    vector<pii>Ed;
    for(i=1;i<=n*m;i++){
        for(auto &t : E[i]){
            Ed.push_back({t,i});
        }
    }
    DD.Do(Ed,Ran);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",DD.Res[Num(i,j)]);
        }
        puts("");
    }
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}