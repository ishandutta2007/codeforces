#include<iostream>
#include<cstdio>
#include<vector>
#define DIM 1000005
using namespace std;
int t, n, m, x, y, nr, i;
int viz[2][DIM], sol[2][DIM], s[2];
vector<int> v[2][DIM];
void dfs(int t, int nod){
    nr++;
    viz[t][nod] = 1;
    for(int i = 0; i < v[t][nod].size(); i++){
        int vecin = v[t][nod][i];
        if(viz[t][vecin] == 0){
            dfs(t, vecin);
        }
    }
}
int main(){
    scanf("%d", &t);
    for(; t; t--){
        scanf("%d%d", &n, &m);
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, & y);
            if(x != y){
                v[0][x].push_back(y);
                v[1][y].push_back(x);
            }
        }
        nr = 0;
        dfs(0, 1);
        if(nr == n){
            nr = 0;
            dfs(1, 1);
            if(nr == n){
                cout<<"No\n";
                for(i = 1; i <= n; i++){
                    viz[0][i] = viz[1][i] = 0;
                    v[0][i].clear();
                    v[1][i].clear();
                }
                continue;
            }
            else{
                x = 1;
            }
        }
        else{
            x = 0;
        }
        s[0] = s[1] = 0;
        for(i = 1; i <= n; i++){
            if(viz[x][i] == 1){
                sol[x][ ++s[x] ] = i;
            }
            else{
                sol[1 - x][ ++s[1 - x] ] = i;
            }
        }
        cout<<"Yes\n";
        cout<< s[0] <<" "<< s[1] <<"\n";
        for(i = 1; i <= s[0]; i++){
            cout<< sol[0][i] <<" ";
        }
        cout<<"\n";
        for(i = 1; i <= s[1]; i++){
            cout<< sol[1][i] <<" ";
        }
        cout<<"\n";
        for(i = 1; i <= n; i++){
            viz[0][i] = viz[1][i] = 0;
            v[0][i].clear();
            v[1][i].clear();
        }
    }
}