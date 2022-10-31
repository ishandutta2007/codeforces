#include<iostream>
#include<vector>
using namespace std;
int n, i, nr, nod1, nod2, num, nod3, nod4, j;
int g[1005], a[1005][1005];
vector<int> v[1005], f[1005];
struct str{
    int x, y, val;
};
str w[1005], sol[5005];
int dfs(int nod, int t){
    if(g[nod] == 1){
        return nod;
    }
    if(v[nod][0] != t){
        return dfs(v[nod][0], nod);
    }
    else{
        return dfs(v[nod][1], nod);
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> w[i].x >> w[i].y >> w[i].val;
        a[ w[i].x ][ w[i].y ] = a[ w[i].y ][ w[i].x ] = w[i].val;
        g[ w[i].x ]++;
        g[ w[i].y ]++;
        v[ w[i].x ].push_back(w[i].y);
        v[ w[i].y ].push_back(w[i].x);
    }
    for(i = 1; i <= n; i++){
        if(g[i] == 2 && a[i][ v[i][0] ] != a[i][ v[i][1] ]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(i = 1; i <= n; i++){
        nod1 = nod2 = 0;
        num = 0;
        for(j = 1; j <= n; j++){
            if(a[i][j] != 0){
                num++;
                if(nod1 == 0){
                    nod1 = j;
                }
                else{
                    nod2 = j;
                }
            }
        }
        if(num == 2){
            a[nod1][nod2] = a[nod2][nod1] = a[i][nod1];
            a[i][nod1] = a[nod1][i] = 0;
            a[i][nod2] = a[nod2][i] = 0;
            for(j = 0; j < v[nod1].size(); j++){
                if(v[nod1][j] == i){
                    v[nod1][j] = nod2;
                }
            }
            for(j = 0; j < v[nod2].size(); j++){
                if(v[nod2][j] == i){
                    v[nod2][j] = nod1;
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j < v[i].size(); j++){
            f[i].push_back( dfs(v[i][j], i) );
        }
    }
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            if(a[i][j] != 0){
                if(g[i] == 1 && g[j] == 1){
                    sol[++nr] = {i, j, a[i][j]};
                    continue;
                }
                if(g[i] != 1){
                    if(v[i][0] != j){
                        nod1 = f[i][0];
                    }
                    else{
                        nod1 = f[i][1];
                    }
                    if(v[i][1] != j && nod1 != f[i][1]){
                        nod2 = f[i][1];
                    }
                    else{
                        nod2 = f[i][2];
                    }
                }
                if(g[j] != 1){
                    if(v[j][0] != i){
                        nod3 = f[j][0];
                    }
                    else{
                        nod3 = f[j][1];
                    }
                    if(v[j][1] != i && nod3 != f[j][1]){
                        nod4 = f[j][1];
                    }
                    else{
                        nod4 = f[j][2];
                    }
                }
                if(g[i] == 1){
                    sol[++nr] = {i, nod3, a[i][j] / 2};
                    sol[++nr] = {i, nod4, a[i][j] / 2};
                    sol[++nr] = {nod3, nod4, -a[i][j] / 2};
                }
                else{
                    if(g[j] == 1){
                        sol[++nr] = {j, nod1, a[i][j] / 2};
                        sol[++nr] = {j, nod2, a[i][j] / 2};
                        sol[++nr] = {nod1, nod2, -a[i][j] / 2};
                    }
                    else{
                        sol[++nr] = {nod1, nod3, a[i][j] / 2};
                        sol[++nr] = {nod2, nod4, a[i][j] / 2};
                        sol[++nr] = {nod1, nod2, -a[i][j] / 2};
                        sol[++nr] = {nod3, nod4, -a[i][j] / 2};
                    }
                }
            }
        }
    }
    cout<< nr <<"\n";
    for(i = 1; i <= nr; i++){
        cout<< sol[i].x <<" "<< sol[i].y <<" "<< sol[i].val <<"\n";
    }
}