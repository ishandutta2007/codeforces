#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define f first
#define s second
using namespace std;
int n, m, q, i, j, ii, x, y, k, nr;
int viz[3005], t[3005], ff[3005], sol[400005], b[3005], cd[3005];
vector<int> v[3005], v2[3005], v3[3005];
struct str{
    int x, k, ind;
};
str aux, c;
vector<str> w[3005];
vector< pair<int, int> > w2[3005];
//ifstream fin("date.in");
//ofstream fout("date.out");
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v2[nod].size(); i++){
        int vecin = v2[nod][i];
        if(viz[vecin] == 0){
            dfs(vecin);
        }
    }
}
void dfs2(int nod){
    ff[nod] = 1;
    cd[++nr] = nod;
    for(int i = 0; i < w2[nod].size(); i++){
        if(w2[nod][i].f <= nr){
            sol[ w2[nod][i].s ] = cd[nr - w2[nod][i].f + 1];
        }
        else{
            sol[ w2[nod][i].s ] = -1;
        }
    }
    for(int i = 0; i < v3[nod].size(); i++){
        int vecin = v3[nod][i];
        if(ff[vecin] == 0){
            dfs2(vecin);
        }
    }
    nr--;
}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v2[y].push_back(x);
    }
    for(i = 1; i <= q; i++){
        scanf("%d%d%d", &x, &y, &k);
        aux.x = x;
        aux.k = k;
        aux.ind = i;
        w[y].push_back(aux);
    }
    for(i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    for(i = 2; i <= n; i++){
        b[i] = b[i / 2] + 1;
    }
    for(ii = 1; ii <= n; ii++){
        if(w[ii].size() == 0){
            continue;
        }
        memset(viz, 0, sizeof(viz));
        memset(ff, 0, sizeof(ff));
        memset(t, 0, sizeof(t));
        dfs(ii);
        for(i = 1; i <= n; i++){
            if(viz[i] == 0 || i == ii){
                continue;
            }
            for(j = 0; j < v[i].size(); j++){
                if(viz[ v[i][j] ] == 1){
                    t[i] = v[i][j];
                    break;
                }
            }
        }
        for(i = 1; i <= n; i++){
            v3[i].clear();
        }
        for(i = 1; i <= n; i++){
            v3[ t[i] ].push_back(i);
            w2[i].clear();
        }
        for(i = 0; i < w[ii].size(); i++){
            aux = w[ii][i];
            w2[aux.x].push_back( make_pair(aux.k, aux.ind) );
        }
        nr = 0;
        dfs2(ii);
    }
    for(i = 1; i <= q; i++){
        if(sol[i] == 0){
            printf("-1\n");
        }
        else{
            printf("%d\n", sol[i]);
        }
    }
    return 0;
}