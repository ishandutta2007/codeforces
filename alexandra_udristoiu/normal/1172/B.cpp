#include<iostream>
#include<vector>
#include<cstdio>
#define DIM 200005
#define mod  998244353
using namespace std;
int n, i, x, y;
int viz[DIM], d[DIM], p[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = d[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            dfs(vecin);
            d[nod] = d[nod] * 1LL * d[vecin] % mod;
        }
    }
    d[nod] = d[nod] * 1LL * p[ v[nod].size() ] % mod;
}
int main(){
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    p[0] = 1;
    for(i = 1; i <= n; i++){
        p[i] = p[i - 1] * 1LL * i % mod;
    }
    dfs(1);
    d[1] = d[1] * 1LL * n % mod;
    cout<< d[1];
}