#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, m, k, i, p, u, nod, vecin, j, minim, maxim, nr, x, y;
int d[DIM], c[DIM], dist[DIM];
vector<int> v[DIM], w[DIM];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        w[y].push_back(x);
    }
    cin>> k;
    for(i = 1; i <= k; i++){
        cin>> d[i];
    }
    p = u = 1;
    c[1] = d[k];
    dist[ c[1] ] = 1;
    while(p <= u){
        nod = c[p];
        p++;
        for(i = 0; i < w[nod].size(); i++){
            vecin = w[nod][i];
            if(dist[vecin] == 0){
                dist[vecin] = dist[nod] + 1;
                c[++u] = vecin;
            }
        }
    }
    for(i = 2; i < k; i++){
        if(dist[ d[i] ] + 1 != dist[ d[i - 1] ]){
            minim++;
            maxim++;
        }
        else{
            nr = 0;
            nod = d[i - 1];
            for(j = 0; j < v[nod].size(); j++){
                if(dist[nod] == 1 + dist[ v[nod][j] ]){
                    nr++;
                }
            }
            if(nr > 1){
                maxim++;
            }
        }
    }
    cout<< minim <<" "<< maxim;
}