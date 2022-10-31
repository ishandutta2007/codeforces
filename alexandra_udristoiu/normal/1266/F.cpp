#include<iostream>
#include<algorithm>
#include<vector>
#define DIM 500005
using namespace std;
int n, i, x, y, j, nr, sol, vecin, ii, nod;
int niv[DIM], dist[DIM], ds[DIM], sn[DIM], sn2[DIM], sm[DIM], p[DIM], aib[2][DIM];
vector<int> v[DIM];
void dfs(int nod, int t){
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            niv[vecin] = 1 + niv[nod];
            dfs(vecin, nod);
            dist[nod] = max(dist[nod], dist[vecin] + 1);
        }
    }
}
void dfs2(int nod, int t){
    int i, vecin, ind, ind2;
    ind = ind2 = 0;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin != t){
            if(dist[vecin] >= dist[ind]){
                ind2 = ind;
                ind = vecin;
            }
            else{
                if(dist[vecin] >= dist[ind2]){
                    ind2 = vecin;
                }
            }
        }
    }
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin != t){
            ds[vecin] = 1 + ds[nod];
            if(vecin != ind){
                ds[vecin] = max(ds[vecin], dist[ind] + 2);
            }
            else{
                if(ind2 != 0){
                    ds[vecin] = max(ds[vecin], dist[ind2] + 2);
                }
            }
            dfs2(vecin, nod);
        }
    }
}
int cmp(int x, int y){
    return x > y;
}
void update(int t, int x, int val){
    for(; x <= n; x += (x & -x) ){
        aib[t][x] = max(aib[t][x], val);
    }
}
void curata(int t, int x){
    for(; x <= n; x += (x & -x) ){
        aib[t][x] = 0;
    }
}
int query(int t, int x){
    int maxim = 0;
    for(; x >= 1; x -= (x & -x) ){
        maxim = max(maxim, aib[t][x]);
    }
    return maxim;
}
int cmp2(int a, int b){
    return dist[a] > dist[b];
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for(i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end(), cmp2);
    }
    for(i = 1; i <= n; i++){
        nr = 1;
        p[1] = ds[i];
        if(p[1] == 0){
            nr = 0;
        }
        for(j = 0; j < v[i].size(); j++){
            vecin = v[i][j];
            if(niv[vecin] > niv[i]){
                p[++nr] = dist[vecin] + 1;
            }
        }
        sort(p + 1, p + nr + 1, cmp);
        for(j = 1; j <= nr; j++){
            sn[ p[j] ] = max(sn[ p[j] ], j);
            if(p[j] < p[j - 1] || j == 1){
                sn2[ p[j] ] = max(sn2[ p[j] ], j);
            }
            update(0, n - p[j] + 1, j);
        }
        for(ii = 0; ii < v[i].size(); ii++){
            nod = v[i][ii];
            if(niv[nod] > niv[i]){
                for(j = 1; j < v[nod].size(); j++){
                    vecin = v[nod][j];
                    sm[ dist[vecin] + 1 ] = max(sm[ dist[vecin] + 1 ], j + query(0, n - dist[vecin]) - 1);
                    update(1, n - dist[vecin], j);
                }
            }
        }
        for(j = 1; j <= nr; j++){
            sm[ p[j] ] = max(sm[ p[j] ], j + query(1, n - p[j] + 1) - 1);
            curata(0, n - p[j] + 1);
        }
        for(ii = 0; ii < v[i].size(); ii++){
            nod = v[i][ii];
            if(niv[nod] > niv[i]){
                for(j = 1; j < v[nod].size(); j++){
                    vecin = v[nod][j];
                    curata(1, n - dist[vecin]);
                }
            }
        }
    }
    sn[n] = sn2[n] = 1;
    for(i = n; i >= 1; i--){
        sm[i] = max(sm[i], sm[i + 1]);
        sn[i] = max(sn[i], sn[i + 1]);
        sn2[i] = max(sn2[i], sn2[i + 1]);
    }
    for(i = 1; i <= n; i++){
        if(v[i].size() + 1 > sol){
            sol = 1 + v[i].size();
        }
    }
    cout<< sol <<" ";
    for(i = 2; i <= n; i++){
        if(i % 2 == 0){
            sol = max(sn[i / 2], sm[i / 2]);
        }
        else{
            sol = max(sn2[i / 2], sn[ (i + 1) / 2 ]);
        }
        cout<< sol <<" ";
    }
}