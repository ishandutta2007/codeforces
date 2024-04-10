#include<iostream>
using namespace std;
int n, ok, i, j, ii, jj, sol;
int a[55][55];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin>> a[i][j];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(a[i][j] == 1){
                sol++;
                continue;
            }
            ok = 0;
            for(ii = 1; ii <= n; ii++){
                for(jj = 1; jj <= n; jj++){
                    if(a[ii][j] + a[i][jj] == a[i][j]){
                        ok = 1;
                    }
                }
            }
            sol += ok;
        }
    }
    if(sol == n * n){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}