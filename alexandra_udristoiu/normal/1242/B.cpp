#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, m, i, x, y, nr, r1, r2, j;
int r[DIM], viz[DIM];
vector<int> v[DIM];
int rad(int x){
    while(r[x] > 0){
        x = r[x];
    }
    return x;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    x = 1;
    r[1] = -1;
    for(i = 2; i <= n; i++){
        if(v[i].size() < v[x].size()){
            x = i;
        }
        r[i] = -1;
    }
    if(v[x].size() < n / 2){
        for(i = 1; i <= n; i++){
            if(v[i].size() < n / 2){
                r1 = rad(x);
                r2 = rad(i);
                if(r1 != r2){
                    if(r[r1] < r[r2]){
                        r[r1] += r[r2];
                        r[r2] = r1;
                    }
                    else{
                        r[r2] += r[r1];
                        r[r1] = r2;
                    }
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(v[i].size() < n / 2){
            continue;
        }
        for(j = 0; j < v[i].size(); j++){
            viz[ v[i][j] ] = i;
        }
        for(j = 1; j <= n; j++){
            if(viz[j] != i){
                r1 = rad(i);
                r2 = rad(j);
                if(r1 != r2){
                    if(r[r1] < r[r2]){
                        r[r1] += r[r2];
                        r[r2] = r1;
                    }
                    else{
                        r[r2] += r[r1];
                        r[r1] = r2;
                    }
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(r[i] < 0){
            nr++;
        }
    }
    cout<< nr - 1;
}