#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef unsigned long long ull;
ull D[60][210][60];
int B[210], E[210], Z[210], w[210], Bad[210], ED[210];
ull Res[210], INF = (1ll<<62);
int K, n, m, cnt, ccc;
struct AA{
    string z;
    bool operator <(const AA &p)const{
        return z.size()<p.z.size();
    }
};
struct Trie{
    int Ch[2];
    int p, fail;
    int c;
}T[210];
void Aho(){
    int Q[210]={0}, head=0,tail=0;
    Q[++tail] = 1;
    int i, j;
    while(head < tail){
        int x = Q[++head];
        if(x==1)T[x].fail=1;
        else if(T[x].p==1)T[x].fail=1;
        else T[x].fail = T[T[T[x].p].fail].Ch[T[x].c];
        for(i=0;i<2;i++){
            if(T[x].Ch[i]) Q[++tail] = T[x].Ch[i];
        }
        for(i=0;i<2;i++){
            if(T[x].Ch[i]) continue;
            int t = T[x].fail;
            T[x].Ch[i] = T[t].Ch[i];
            if(!T[x].Ch[i])T[x].Ch[i]=1;
        }
    }
    for(i=1;i<=ccc;i++){
        for(j=0;j<2;j++){
            if(Bad[i] || Bad[T[i].Ch[j]])T[i].Ch[j] = 0;
            if(T[i].Ch[j]){
                //printf("%d %d %d\n",i,j,T[i].Ch[j]);
            }
        }
    }
}
struct BB{
    int x, y, z;
    ull d;
    bool operator <(const BB &p)const{
        return d>p.d;
    }
};
priority_queue<BB>PQ;
void Put(int i, int j, int k, ull d){
    if(D[i][j][k]<=d)return;
    if(Bad[i]||Bad[k])return;
    D[i][j][k]=d;
    PQ.push({i,j,k,d});
}
int main(){
    int i, j, k;
    scanf("%d%d%d",&K,&n,&m);
    for(i=1;i<=n;i++){
        int a, c;
        scanf("%d%d",&a,&c);
        Z[i] = a;
        B[i] = ++cnt;
        w[cnt] = 0;
        for(j=0;j<c;j++){
            cnt++;
            scanf("%d",&w[cnt]);
        }
        E[i]=cnt;
        ED[cnt] = i;
    }
    vector<AA>VV;
    for(i=1;i<=m;i++){
        int a, c;
        scanf("%d",&c);
        string s="";
        while(c){
            scanf("%d",&a);
            if(a)s+='1';
            else s+='0';
            c--;
        }
        VV.push_back({s});
    }
    sort(VV.begin(),VV.end());
    vector<string>V;
    for(i=0;i<m;i++){
        for(j=0;j<i;j++){
            if(VV[i].z.find(VV[j].z)!=string::npos)break;
        }
        if(j==i)V.push_back(VV[i].z);
    }
    ccc = 1;
    for(auto &t : V){
        int cur = 1;
        for(auto &ch : t){
            int c = ch-'0';
            if(!T[cur].Ch[c]){
                T[cur].Ch[c]=++ccc;
                T[ccc].p = cur;
                T[ccc].c = c;
            }
            cur = T[cur].Ch[c];
        }
        Bad[cur] = 1;
    }
    Aho();
    for(i=1;i<=ccc;i++){
        for(j=1;j<=cnt;j++){
            for(k=1;k<=ccc;k++){
                D[i][j][k]=INF;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=ccc;j++){
            if(Bad[j])continue;
            Put(j,B[i],j,0);
        }
    }
    while(!PQ.empty()){
        BB t = PQ.top();
        PQ.pop();
        if(D[t.x][t.y][t.z]!=t.d)continue;
        if(ED[t.y]){
            int x = Z[ED[t.y]];
            for(i=1;i<=cnt;i++){
                if(w[i] == x){
                    for(j=1;j<=ccc;j++){
                        if(Bad[j])continue;
                        Put(j, i, t.z, D[j][i-1][t.x] + t.d);
                    }
                }
            }
        }
        else{
            int x = w[t.y+1];
            if(x==0 || x==1){
                Put(t.x, t.y+1, T[t.z].Ch[x], t.d+1);
            }
            else{
                for(i=1;i<=n;i++){
                    if(Z[i]!=x)continue;
                    for(j=1;j<=ccc;j++){
                        Put(t.x, t.y+1, j, t.d+D[t.z][E[i]][j]);
                    }
                }
            }
        }
    }
    for(i=1;i<=K;i++)Res[i]=INF;
    for(i=1;i<=n;i++){
        for(j=1;j<=ccc;j++){
            if(Bad[j])continue;
            if(Res[Z[i]] > D[1][E[i]][j]){
                Res[Z[i]] = D[1][E[i]][j];
            }
        }
    }
    for(i=2;i<K;i++){
        if(Res[i]>=INF)puts("YES");
        else printf("NO %llu\n",Res[i]);
    }
}