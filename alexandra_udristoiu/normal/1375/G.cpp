#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, y, nr0, nr1;
int viz[DIM];
vector<int> v[DIM];
void dfs(int nod, int niv){
    viz[nod] = 1;
    if(niv % 2 == 0){
        nr0++;
    }
    else{
        nr1++;
    }
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            dfs(vecin, niv + 1);
        }
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
    cout<< min(nr0, nr1) - 1;
}