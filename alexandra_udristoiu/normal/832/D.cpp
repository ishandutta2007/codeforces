#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, q, i, x, nr, ii, jj, j;
int d[2 * DIM],  niv2[2 * DIM], first[DIM], b[2 * DIM], niv[DIM], sol[DIM], a1[4];
int a[18][2 * DIM];
vector<int> v[DIM];
void dfs(int nod, int ni){
    nr++;
    niv[nod] = ni;
    d[nr] = nod;
    niv2[nr] = ni;
    first[nod] = nr;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        dfs(vecin, ni + 1);
        nr++;
        d[nr] = nod;
        niv2[nr] = ni;
    }
}
int lca(int x, int y){
    int ii, jj, p, minim;
    ii = first[x];
    jj = first[y];
    if(ii > jj){
        swap(ii, jj);
    }
    p = b[jj - ii + 1];
    if(niv2[ a[p][ii] ] < niv2[ a[p][jj - (1 << p) + 1] ]){
        minim = a[p][ii];
    }
    else{
        minim = a[p][jj - (1 << p) + 1];
    }
    return d[minim];
}
int solve(int s, int t, int f){
    int x, y, sol = 0, z;
    x = lca(s, f);
    y = lca(t, f);
    sol = niv[f] - max(niv[x], niv[y]) + 1;
    if(x == y){
        z = lca(s, t);
        sol += niv[z] - niv[y];
    }
    return sol;
}
int main(){
    cin>> n >> q;
    for(i = 2; i <= n; i++){
        cin>> x;
        v[x].push_back(i);
    }
     dfs(1, 1);
    for(i = 2; i <= nr; i++){
        b[i] = b[i / 2] + 1;
    }
    for(i = 1; i <= nr; i++){
        a[0][i] = i;
    }
     for(i = 1; (1 << i) <= nr; i++){
        for(j = 1; j <= nr - (1 << i); j++){
            a[i][j] = a[i-1][j];
            if(niv2[ a[i][j] ] > niv2[ a[i-1][j+ (1 << (i - 1)) ] ]){
                a[i][j] = a[i-1][j+ (1 << (i - 1)) ];
            }
        }
    }
    for(i = 1; i <= q; i++){
         cin>> a1[1] >> a1[2] >> a1[3];
         for(ii = 1; ii <= 3; ii++){
            for(j = 1; j <= 3; j++){
                for(jj = 1; jj <= 3; jj++){
                    if(ii != j && j != jj && ii != jj){
                        sol[i] = max(sol[i], solve(a1[ii], a1[j], a1[jj]) );
                    }
                }
            }
         }
    }
    for(i = 1; i <= q; i++){
        cout<< sol[i] <<"\n";
    }
    return 0;
}