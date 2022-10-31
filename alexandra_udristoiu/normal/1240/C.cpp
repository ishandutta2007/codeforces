#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define DIM 500005
#define f first
#define s second
using namespace std;
int t, n, k, i, x, y, c, nr;
long long d[DIM][2], w[DIM];
vector< pair<int, int> > v[DIM];
int cmp(long long a, long long b){
    return a > b;
}
void dfs(int nod, int t){
    int i, vecin;
    d[nod][0] = d[nod][1] = 0;
    for(i = 0; i < v[nod].size(); i++){
        if(v[nod][i].f != t){
            dfs(v[nod][i].f, nod);
        }
    }
    nr = 0;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i].f;
        if(vecin == t){
            continue;
        }
        d[nod][0] += d[vecin][1];
        if(d[vecin][1] < d[vecin][0] + v[nod][i].s){
            w[++nr] = d[vecin][0] + v[nod][i].s - d[vecin][1];
        }
    }
    d[nod][1] = d[nod][0];
    sort(w + 1, w + nr + 1, cmp);
    for(i = 1; i <= min(nr, k - 1); i++){
        d[nod][0] += w[i];
        d[nod][1] += w[i];
    }
    if(nr >= k){
        d[nod][1] += w[k];
    }
}
int main(){
    scanf("%d", &t);
    for(; t; t--){
        scanf("%d%d", &n, &k);
        for(i = 1; i <= n; i++){
            v[i].clear();
        }
        for(i = 1; i < n; i++){
            scanf("%d%d%d", &x, &y, &c);
            v[x].push_back( make_pair(y, c) );
            v[y].push_back( make_pair(x, c) );
        }
        dfs(1, 0);
        cout<< d[1][1] <<"\n";
    }
}