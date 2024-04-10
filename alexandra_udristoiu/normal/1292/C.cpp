#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define f first
#define s second
using namespace std;
int n, i, j, x, y, k;
int dist[3005][3005], viz[3005], t[3005][3005], num[3005][3005];
long long d[3005][3005], sol;
pair<int, int> p[4600000];
vector<int> v[3005];
int cmp(pair<int, int> a, pair<int, int> b){
    return dist[a.f][a.s] < dist[b.f][b.s];
}
void dfs(int nod, int r){
    viz[nod] = 1;
    num[r][nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            t[r][vecin] = nod;
            dist[r][vecin] = 1 + dist[r][nod];
            dfs(vecin, r);
            num[r][nod] += num[r][vecin];
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= n; i++){
        memset(viz, 0, sizeof(viz) );
        dfs(i, i);
        for(j = i + 1; j <= n; j++){
            p[++k] = make_pair(i, j);
        }
    }
    sort(p + 1, p + k + 1, cmp);
    for(i = 1; i <= k; i++){
        x = p[i].f;
        y = p[i].s;
        d[x][y] = num[x][y] * num[y][x] + max(d[x][ t[x][y] ], d[ t[y][x] ][y]);
        d[y][x] = d[x][y];
        sol = max(sol, d[x][y]);
    }
    cout<< sol;
}