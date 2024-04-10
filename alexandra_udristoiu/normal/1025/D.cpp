#include<iostream>
using namespace std;
int n, i, j, ii, jj, c, d, r;
int v[705], cmmdc[705][705], a[705][705], b[705][705];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            c = v[i];
            d = v[j];
            while(d != 0){
                r = c % d;
                c = d;
                d = r;
            }
            cmmdc[i][j] = cmmdc[j][i] = c;
        }
    }
    for(i = 1; i <= n; i++){
        if(i != 1 && cmmdc[i - 1][i] != 1){
            a[i][i] = 1;
        }
        if(i != n && cmmdc[i][i + 1] != 1){
            b[i][i] = 1;
        }
    }
    for(ii = 2; ii < n; ii++){
        for(i = 1; i <= n - ii + 1; i++){
            j = i + ii - 1;
            if(i != 1){
                if(cmmdc[i - 1][i] != 1 && a[i + 1][j] == 1){
                    a[i][j] = 1;
                }
                if(cmmdc[i - 1][j] != 1 && b[i][j - 1] == 1){
                    a[i][j] = 1;
                }
                for(jj = i + 1; jj < j && a[i][j] == 0; jj++){
                    if(cmmdc[i - 1][jj] != 1 && a[jj + 1][j] == 1 && b[i][jj - 1] == 1){
                        a[i][j] = 1;
                    }
                }
            }
            if(j != n){
                if(cmmdc[i][j + 1] != 1 && a[i + 1][j] == 1){
                    b[i][j] = 1;
                }
                if(cmmdc[j][j + 1] != 1 && b[i][j - 1] == 1){
                    b[i][j] = 1;
                }
                for(jj = i + 1; jj < j && b[i][j] == 0; jj++){
                    if(cmmdc[jj][j + 1] != 1 && a[jj + 1][j] == 1 && b[i][jj - 1] == 1){
                        b[i][j] = 1;
                    }
                }
            }
        }
    }
    if(a[2][n] == 1 || b[1][n - 1] == 1){
        cout<<"Yes";
        return 0;
    }
    for(i = 2; i < n; i++){
        if(b[1][i - 1] == 1 && a[i + 1][n] == 1){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}