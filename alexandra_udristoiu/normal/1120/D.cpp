#include<iostream>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, i, x, y, nr;
long long sum;
int val[DIM], h[DIM], p[DIM], sol[DIM];
vector<int> v[DIM], w[DIM];
void dfs(int nod, int t){
    if(nod != 1 && v[nod].size() == 1){
        h[nod] = val[nod];
        p[nod] = nod;
        w[nod].push_back(nod);
        return;
    }
    int i, ind, maxim, ok, vecin, j;
    for(i = 0; i < v[nod].size(); i++){
        if(v[nod][i] != t){
            dfs(v[nod][i], nod);
        }
    }
    maxim = -1;
    ok = 1;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin == t){
            continue;
        }
        if(h[vecin] > maxim){
            maxim = h[vecin];
            ind = vecin;
            ok = 1;
        }
        else{
            if(h[vecin] == maxim){
                ok = 0;
            }
        }
    }
    h[nod] = min(maxim, val[nod]);
    sum += h[nod] - maxim;
    if(ok == 1){
        for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i];
            if(vecin != t && vecin != ind){
                for(j = 0; j < w[ p[vecin] ].size(); j++){
                    sol[ w[ p[vecin] ][j] ] = 1;
                }
            }
        }
        if(maxim > val[nod]){
            p[nod] = nod;
            w[nod].push_back(nod);
        }
        else{
            p[nod] = p[ind];
            if(maxim == val[nod]){
                w[ p[nod] ].push_back(nod);
            }
        }
    }
    else{
         for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i];
            if(vecin != t){
                for(j = 0; j < w[ p[vecin] ].size(); j++){
                    sol[ w[ p[vecin] ][j] ] = 1;
                }
            }
        }
        p[nod] = nod;
        if(maxim >= val[nod]){
            w[nod].push_back(nod);
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> val[i];
    }
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 2; i <= n; i++){
        if(v[i].size() == 1){
            sum += val[i];
        }
    }
    dfs(1, 0);
    for(i = 0; i < w[ p[1] ].size(); i++){
        sol[ w[ p[1] ][i] ] = 1;
    }
    for(i = 1; i <= n; i++){
        nr += sol[i];
    }
    cout<< sum <<" "<< nr <<"\n";
    for(i = 1; i <= n; i++){
        if(sol[i] == 1){
            cout<< i <<" ";
        }
    }
}