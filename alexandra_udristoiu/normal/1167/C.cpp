#include<iostream>
#include<vector>
#define DIM 500005
using namespace std;
int n, m, i, j, x, k;
int vizf[DIM], vizg[DIM], c[DIM], nr[DIM];
vector<int> v[DIM], w[DIM];
void dfs1(int nod);
void dfs2(int nod);
void dfs1(int nod){
    vizf[nod] = 1;
    c[nod] = k;
    nr[k]++;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vizg[vecin] == 0){
            dfs2(vecin);
        }
    }
}
void dfs2(int nod){
    vizg[nod] = 1;
    for(int i = 0; i < w[nod].size(); i++){
        int vecin = w[nod][i];
        if(vizf[vecin] == 0){
            dfs1(vecin);
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> k;
        for(j = 1; j <= k; j++){
            cin>> x;
            w[i].push_back(x);
            v[x].push_back(i);
        }
    }
    k = 0;
    for(i = 1; i <= n; i++){
        if(vizf[i] == 0){
            k++;
            dfs1(i);
        }
    }
    for(i = 1; i <= n; i++){
        cout<< nr[ c[i] ] <<" ";
    }
}