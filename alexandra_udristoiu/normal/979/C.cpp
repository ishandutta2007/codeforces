#include<iostream>
#include<vector>
#define DIM 300005
using namespace std;
int n, i, x, y, a, b;
long long sol;
int num[DIM], viz[DIM], t[DIM], niv[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = num[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            niv[vecin] = niv[nod] + 1;
            t[vecin] = nod;
            dfs(vecin);
            num[nod] += num[vecin];
        }
    }
}
int main(){
    cin>> n >> x >> y;
    for(i = 1; i < n; i++){
        cin>> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    if(niv[x] < niv[y]){
        swap(x, y);
    }
    a = x;
    while(a != 0){
        if(a == y){
            break;
        }
        a = t[a];
    }
    sol = n * 1LL * (n - 1);
    if(a == 0){
        sol -= num[x] * 1LL * num[y];
    }
    else{
        a = x;
        while(t[a] != y){
            a = t[a];
        }
        sol -= num[x] * 1LL * (n - num[a]);
    }
    cout<< sol;
}