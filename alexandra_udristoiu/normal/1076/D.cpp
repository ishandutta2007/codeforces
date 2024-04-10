#include<iostream>
#include<vector>
#define DIM 300005
using namespace std;
int n, m, i, j, x, y, z, nod, vecin, u, k, sol;
int ff[DIM], c[DIM], nr[DIM], viz[DIM], poz[DIM], h[DIM];
long long d[DIM];
struct str{
    int vec, ind, cost;
};
vector<str> v[DIM];
str t[DIM];
void upd(int pos){
    int c = pos, p = c / 2;
    while(p > 0 && d[ h[p] ] > d[ h[c] ]){
        swap(h[p], h[c]);
        poz[ h[p] ] = p;
        poz[ h[c] ] = c;
        c = p;
        p = c / 2;
    }
}
void elim(){
    int p = 1, c = 2;
    while(c <= n){
        if(c + 1 <= n && d[ h[c] ] > d[ h[c + 1] ]){
            c++;
        }
        if(d[ h[p] ] < d[ h[c] ]){
            break;
        }
        swap(h[p], h[c]);
        poz[ h[p] ] = p;
        poz[ h[c] ] = c;
        p = c;
        c = 2 * p;
    }
}
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= m; i++){
        cin>> x >> y >> z;
        v[x].push_back( {y, i, z} );
        v[y].push_back( {x, i, z} );
    }
    for(i = 1; i <= n; i++){
        h[i] = poz[i] = i;
        d[i] = 1000000000000000LL;
    }
    d[1] = 0;
    for(i = 1; i <= n; i++){
        nod = h[1];
        ff[ t[nod].ind ] = 1;
        nr[ t[nod].vec ]++;
        for(j = 0; j < v[nod].size(); j++){
            vecin = v[nod][j].vec;
            if(viz[vecin] == 0 && d[vecin] > d[nod] + v[nod][j].cost){
                d[vecin] = d[nod] + v[nod][j].cost;
                t[vecin] = {nod, v[nod][j].ind, 0};
                upd(poz[vecin]);
            }
        }
        d[nod] = 1000000000000000LL;
        viz[nod] = 1;
        elim();
    }
    sol = min(k, n - 1);
    k = n - 1 - k;
    for(i = 1; i <= n; i++){
        if(nr[i] == 0){
            c[++u] = i;
        }
    }
    for(i = 1; i <= k; i++){
        nod = c[i];
        ff[ t[nod].ind ] = 0;
        nr[ t[nod].vec ]--;
        if(nr[ t[nod].vec ] == 0){
            c[++u] = t[nod].vec;
        }
    }
    cout<< sol <<"\n";
    for(i = 1; i <= m; i++){
        if(ff[i] == 1){
            cout<< i <<" ";
        }
    }
}