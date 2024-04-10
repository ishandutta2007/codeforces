#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
int n, i, j, x;
int viz[1005];
vector<int> v[1005];
long double sol, d[1005][2][2], s[2][2];
struct str{
    int x, y, r;
};
str w[1005];
int cost(int x){
    if(x == 1){
        return -1;
    }
    return 1;
}
long long dist(int i, int j){
    return (w[i].x - w[j].x) * 1LL * (w[i].x - w[j].x) + (w[i].y - w[j].y) * 1LL * (w[i].y - w[j].y);
}
void dfs(int nod){
    int i, j, vecin, ii;
    for(i = 0; i < v[nod].size(); i++){
        dfs(v[nod][i]);
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            s[i][j] = 0;
        }
    }
    for(ii = 0; ii < v[nod].size(); ii++){
        vecin = v[nod][ii];
        for(i = 0; i < 2; i++){
            for(j = 0; j < 2; j++){
                s[i][j] += d[vecin][i][j];
            }
        }
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            d[nod][i][j] = max(s[1 - i][j] + cost(i) * 1LL * w[nod].r * w[nod].r * M_PI,
                               s[i][1 - j] + cost(j) * 1LL * w[nod].r * w[nod].r * M_PI);
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> w[i].x >> w[i].y >> w[i].r;
    }
    w[0].r = 10000000;
    for(i = 1; i <= n; i++){
        x = 0;
        for(j = 1; j <= n; j++){
            if(w[j].r > w[i].r && (w[j].r - w[i].r) * 1LL * (w[j].r - w[i].r) >= dist(i, j) ){
                if(w[j].r < w[x].r){
                    x = j;
                }
            }
        }
        if(x == 0){
            viz[i] = 1;
        }
        else{
            v[x].push_back(i);
        }
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 1){
            dfs(i);
            sol += d[i][0][0];
        }
    }
    cout<< setprecision(9) << fixed << sol;
    return 0;
}