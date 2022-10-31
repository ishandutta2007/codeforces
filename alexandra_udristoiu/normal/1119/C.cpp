#include<iostream>
using namespace std;
int n, m, i, j, ok;
int b[505][505], a[505][505], lin[505], col[505];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> b[i][j];
            if(b[i][j] != a[i][j]){
                lin[i]++;
                col[j]++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(lin[i] % 2 == 1){
            ok = 1;
        }
    }
    for(i = 1; i <= m; i++){
        if(col[i] % 2 == 1){
            ok = 1;
        }
    }
    if(ok == 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}