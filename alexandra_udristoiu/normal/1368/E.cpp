#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, ok, j, nr, x, y, m, t;
int viz[DIM], sol[DIM];
vector<int> v[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m;
        for(i = 1; i <= n; i++){
            viz[i] = 0;
            v[i].clear();
        }
        for(i = 1; i <= m; i++){
            cin>> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        nr = 0;
        for(i = 1; i <= n; i++){
            if(viz[i] == 1){
                continue;
            }
            ok = 0;
            for(j = 0; j < v[i].size(); j++){
                if(viz[ v[i][j] ] == 0){
                    if(v[i][j] < i){
                        ok = 1;
                    }
                }
            }
            if(ok == 1){
                for(j = 0; j < v[i].size(); j++){
                    if(viz[ v[i][j] ] == 0){
                        if(v[i][j] > i){
                            x = v[i][j];
                            viz[x] = 1;
                            sol[++nr] = x;
                        }
                    }
                }
            }
        }
        cout<< nr <<"\n";
        for(i = 1; i <= nr; i++){
            cout<< sol[i] <<" ";
        }
        cout<<"\n";
    }
}