#include<iostream>
#include<vector>
#include<cstdio>
#define d first
#define cost second
#define DIM 300005
using namespace std;
int n, i, m, x, y, z;
int viz[DIM], niv[DIM];
long long s[DIM], sol[DIM];
vector<int> v[DIM];
vector< pair<int, int> > q[DIM];
void dfs(int nod){
    viz[nod] = 1;
    sol[nod] -= s[ niv[nod] ];
    int i;
    for(i = 0; i < q[nod].size(); i++){
        sol[nod] += q[nod][i].cost;
        s[ min(niv[nod] + 1 + q[nod][i].d, n) ] += q[nod][i].cost;
    }
    for(i = 0; i < v[nod].size(); i++){
        if(viz[ v[nod][i] ] == 0){
            niv[ v[nod][i] ] = 1 + niv[nod];
            sol[ v[nod][i] ] = sol[nod];
            dfs(v[nod][i]);
        }
    }
     for(i = 0; i < q[nod].size(); i++){
        s[ min(niv[nod] + 1 + q[nod][i].d, n) ] -= q[nod][i].cost;
    }
}
int main(){
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d", &m);
    for(i = 1; i <= m; i++){
        scanf("%d%d%d", &x, &y, &z);
        q[x].push_back( make_pair(y, z) );
    }
    dfs(1);
    for(i = 1; i <= n; i++){
        cout<< sol[i] <<" ";
    }
}