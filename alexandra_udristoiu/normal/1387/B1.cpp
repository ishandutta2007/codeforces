#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, x, y, nr;
int w[DIM], sol[DIM];
vector<int> v[DIM];
void dfs(int nod, int t){
    int i, vecin, m;
    for(i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            dfs(vecin, nod);
        }
    }
    m = 0;
    for(i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            if(sol[vecin] == 0){
                w[++m] = vecin;
            }
        }
    }
    if(m != 0){
        w[++m] = nod;
        nr += 2 * (m - 1);
        for(i = 1; i < m; i++){
            sol[ w[i] ] = w[i + 1];
        }
        sol[ w[m] ] = w[1];
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    if(sol[1] == 0){
        nr += 2;
        sol[1] = v[1][0];
        for(i = 2; i <= n; i++){
            if(sol[i] == v[1][0]){
                sol[i] = 1;
                break;
            }
        }
    }
    cout<< nr <<"\n";
    for(i = 1; i <= n; i++){
        cout<< sol[i] <<" ";
    }
}