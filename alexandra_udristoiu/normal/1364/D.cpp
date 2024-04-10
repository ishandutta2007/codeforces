#include<iostream>
#include<vector>
#define DIM 200005
#define f first
#define s second
using namespace std;
int n, k, m, i, x, y, minim, nod, lg, nr, xc, yc, ii;
int a[18][DIM], pt[DIM], viz[DIM], niv[DIM], t[DIM], cic[DIM], frst[DIM];
vector<int> v[DIM];
pair<int, int> w[DIM];
void dfs(int nod){
    viz[nod] = 1;
    a[0][++nr] = nod;
    frst[nod] = nr;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            niv[vecin] = niv[nod] + 1;
            t[vecin] = nod;
            dfs(vecin);
            a[0][++nr] = nod;
        }
    }
}
int lca(int x, int y){
    x = frst[x];
    y = frst[y];
    if(x > y){
        swap(x, y);
    }
    int p = pt[y - x + 1];
    if(niv[ a[p][x] ] < niv[ a[p][y - (1 << p) + 1] ]){
        return a[p][x];
    }
    else{
        return a[p][y - (1 << p) + 1];
    }
}
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        w[i] = make_pair(x, y);
    }
    dfs(1);
    if(m == n - 1){
        cout<<"1\n";
        nr = 0;
        for(i = 1; i <= n; i++){
            if(niv[i] % 2 == 0){
                nr++;
            }
        }
        if(nr >= k / 2 + k % 2){
            ii = 0;
        }
        else{
            ii = 1;
        }
        k = k / 2 + k % 2;
        for(i = 1; i <= n; i++){
            if(niv[i] % 2 == ii && k > 0){
                cout<< i <<" ";
                k--;
            }
        }
        return 0;
    }
    for(ii = 1; (1 << ii) <= nr; ii++){
        for(i = 1; i <= nr - (1 << ii) + 1; i++){
            a[ii][i] = a[ii - 1][i];
            if(niv[ a[ii][i] ] > niv[ a[ii - 1][i + (1 << (ii - 1) )] ]){
                a[ii][i] = a[ii - 1][ i + (1 << (ii - 1) ) ];
            }
        }
    }
    for(i = 2; i <= nr; i++){
        pt[i] = 1 + pt[i / 2];
    }
    minim = n + 1;
    for(i = 1; i <= m; i++){
        x = w[i].f;
        y = w[i].s;
        if(t[x] == y || t[y] == x){
            continue;
        }
        nod = lca(x, y);
        lg = niv[x] + niv[y] - 2 * niv[nod] + 1;
        if(minim > lg){
            minim = lg;
            xc = x;
            yc = y;
        }
    }
    nr = 0;
    nod = lca(xc, yc);
    for(x = xc; x != nod; x = t[x]){
        cic[++nr] = x;
    }
    cic[++nr] = nod;
    nr = minim;
    for(x = yc; x != nod; x = t[x]){
        cic[nr--] = x;
    }
    if(minim <= k){
        cout<<"2\n" << minim <<"\n";
        for(i = 1; i <= minim; i++){
            cout<< cic[i] <<" ";
        }
    }
    else{
        cout<<"1\n";
        lg = k / 2 + k % 2;
        for(i = 1; i < 2 * lg + 1; i += 2){
            cout<< cic[i] <<" ";
        }
    }
}