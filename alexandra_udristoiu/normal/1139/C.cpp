#include<iostream>
#include<vector>
#define DIM 100005
#define mod 1000000007
using namespace std;
int n, k, i, x, y, c, j, sol, sum, nr;
int viz[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    nr++;
    for(int i = 0; i < v[nod].size(); i++){
        if(viz[ v[nod][i] ] == 0){
            dfs(v[nod][i]);
        }
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i < n; i++){
        cin>> x >> y >> c;
        if(c == 0){
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            nr = 0;
            dfs(i);
            sum = 1;
            for(j = 1; j <= k; j++){
                sum = sum * 1LL * nr % mod;
            }
            sol = (sol + sum) % mod;
        }
    }
    sum = 1;
    for(i = 1; i <= k; i++){
        sum = sum * 1LL * n % mod;
    }
    sol = (sum - sol + mod) % mod;
    cout<< sol;
}