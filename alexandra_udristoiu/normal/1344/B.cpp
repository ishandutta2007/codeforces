#include<iostream>
using namespace std;
int n, m, i, j, ok1, ok2, nr, ok, p, u;
char a[1005][1005], viz[1005][1005], b[1005][1005];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
void fil(int ii, int jj){
    viz[ii][jj] = 1;
    for(int d = 0; d < 4; d++){
        int iv = ii + di[d];
        int jv = jj + dj[d];
        if(a[iv][jv] == '#' && viz[iv][jv] == 0){
            fil(iv, jv);
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> a[i] + 1;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i][j] == '#'){
                break;
            }
        }
        if(j == m + 1){
            ok1 = 1;
            continue;
        }
        p = j;
        for(j = m; j >= 1; j--){
            if(a[i][j] == '#'){
                u = j;
                break;
            }
        }
        for(j = p; j <= u; j++){
            if(a[i][j] == '.'){
                ok = 1;
                break;
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            b[j][i] = a[i][j];
        }
    }
    swap(n, m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(b[i][j] == '#'){
                break;
            }
        }
        if(j == m + 1){
            ok2 = 1;
            continue;
        }
        p = j;
        for(j = m; j >= 1; j--){
            if(b[i][j] == '#'){
                u = j;
                break;
            }
        }
        for(j = p; j <= u; j++){
            if(b[i][j] == '.'){
                ok = 1;
                break;
            }
        }
    }
    swap(n, m);
    if(ok == 1 || ok1 != ok2){
        cout<< -1;
        return 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i][j] == '#' && viz[i][j] == 0){
                nr++;
                fil(i, j);
            }
        }
    }
    cout<< nr;
}