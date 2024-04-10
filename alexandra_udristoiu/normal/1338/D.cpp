#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, x, y, sol;
int d[DIM][2], viz[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    if(v[nod].size() == 1 && nod != 1){
        d[nod][1] = 1;
        return;
    }
    int i, vecin, ii, c[2];
    c[0] = c[1] = 0;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(viz[vecin] == 1){
            continue;
        }
        dfs(vecin);
        for(ii = 0; ii < 2; ii++){
            if(d[vecin][ii] > d[nod][1 - ii]){
                c[1 - ii] = d[nod][1 - ii];
                d[nod][1 - ii] = d[vecin][ii];
            }
            else{
                c[1 - ii] = max(d[vecin][ii], c[1 - ii]);
            }
        }
    }
    d[nod][0] += v[nod].size() - 1 - (nod != 1);
    d[nod][1]++;
    sol = max(sol, d[nod][0]);
    sol = max(sol, d[nod][0] + c[0] - (nod == 1) );
    sol = max(sol, d[nod][1] + c[1]);
    d[nod][1] = max(d[nod][1], d[nod][0]);
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sol = 1;
    dfs(1);
    cout<< sol;
}