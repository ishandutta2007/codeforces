#include<iostream>
#include<algorithm>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, y, k;
long long sol;
int viz[DIM], niv[DIM], num[DIM];
pair<int, int> p[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    num[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            niv[vecin] = niv[nod] + 1;
            dfs(vecin);
            num[nod] += num[vecin];
        }
    }
    if(v[nod].size() == 1 && nod != 1){
        p[nod] = make_pair(niv[nod], nod);
    }
    else{
        p[nod] = make_pair(niv[nod] - num[nod] + 1, nod);
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    sort(p + 1, p + n + 1);
    for(i = n; i >= n - k + 1; i--){
        sol += p[i].first;
    }
    cout<< sol;
}