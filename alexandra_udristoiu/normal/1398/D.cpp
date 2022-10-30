#include<iostream>
#include<algorithm>
using namespace std;
int i, j, ii, n[3], sol;
int a[3][205], d[205][205][205];
int cmp(int a, int b){
    return a > b;
}
int main(){
    cin>> n[0] >> n[1] >> n[2];
    for(ii = 0; ii < 3; ii++){
        for(i = 1; i <= n[ii]; i++){
            cin>> a[ii][i];
        }
    }
    for(ii = 0; ii < 3; ii++){
        sort(a[ii] + 1, a[ii] + n[ii] + 1, cmp);
    }
    d[0][0][0] = 0;
    for(i = 0; i <= n[0]; i++){
        for(j = 0; j <= n[1]; j++){
            for(ii = 0; ii <= n[2]; ii++){
                sol = max(sol, d[i][j][ii]);
                d[i + 1][j + 1][ii] = max(d[i + 1][j + 1][ii], d[i][j][ii] + a[0][i + 1] * a[1][j + 1]);
                d[i + 1][j][ii + 1] = max(d[i + 1][j][ii + 1], d[i][j][ii] + a[0][i + 1] * a[2][ii + 1]);
                d[i][j + 1][ii + 1] = max(d[i][j + 1][ii + 1], d[i][j][ii] + a[2][ii + 1] * a[1][j + 1]);
            }
        }
    }
    cout<< sol;
}