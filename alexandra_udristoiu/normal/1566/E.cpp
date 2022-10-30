#include<iostream>
#include<algorithm>
#include<vector>
#define DIM 200005
using namespace std;
int t, n, i, sol, x, y, nr;
vector<int> v[DIM];
int b[DIM], ib[DIM];
void dfs(int nod, int t) {
    int nrf = 0;
    for (int i = 0; i < v[nod].size(); i++) {
        int vecin = v[nod][i];
        if (vecin != t) {
            dfs(vecin, nod);
            if (ib[vecin] == 0) {
                nrf++;
            }
        }
    }
    if (nod != 1) {
        if (nrf > 0) {
            b[++nr] = nrf;
            ib[nod] = 1;
        }
    }
    else {
        sol = nrf;
        if (sol == 0) {
            sol = 1;
        }
    }
}
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> n;
        for (i = 1; i <= n; i++) {
            v[i].clear();
            ib[i] = 0;
        }
        for (i = 1; i < n; i++) {
            cin>> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        nr = 0;
        dfs(1, 0);
        for (i = 1; i <= nr; i++) {
            sol += b[i] - 1;
        }
        cout<< sol <<"\n";
    }
}