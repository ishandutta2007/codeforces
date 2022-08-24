#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, w[101000], P[101000][2], PC[101000];
vector<int>E[201000];
bool v[201000];
int SCC[201000], cnt, ord[201000];
void DFS(int a){
    v[a]=true;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
    ord[++cnt] = a;
}
void DFS2(int a){
    SCC[a] = cnt;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!SCC[E[a][i]])DFS2(E[a][i]);
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=m;i++){
        int c, a;
        scanf("%d",&c);
        while(c--){
            scanf("%d",&a);
            P[a][PC[a]++] = i;
        }
    }
    for(i=1;i<=n;i++){
        if(w[i] == 0){
            E[P[i][0]].push_back(P[i][1] + m);
            E[P[i][1]].push_back(P[i][0] + m);
            E[P[i][0] + m].push_back(P[i][1]);
            E[P[i][1] + m].push_back(P[i][0]);
        }
        else{
            E[P[i][0]].push_back(P[i][1]);
            E[P[i][1]].push_back(P[i][0]);
            E[P[i][0] + m].push_back(P[i][1] + m);
            E[P[i][1] + m].push_back(P[i][0] + m);
        }
    }
    for(i=1;i<=m+m;i++){
        if(!v[i])DFS(i);
    }
    cnt = 0;
    for(i=m+m;i>=1;i--){
        if(!SCC[ord[i]]){
            cnt++;
            DFS2(ord[i]);
        }
    }
    for(i=1;i<=m;i++){
        if(SCC[i]==SCC[i+m]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}