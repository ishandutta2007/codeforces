#include<iostream>
using namespace std;
int k, n, m, i, j;
char a[2005][2005];
int main(){
    cin>> k;
    for(i = 5; i <= k; i++){
        if(k % i == 0 && k / i >= 5){
            n = i;
            m = k / i;
            break;
        }
    }
    if(n == 0){
        cout<< -1;
        return 0;
    }
    a[1][1] = a[2][2] = a[3][3] = a[4][4] = a[5][5] = 'a';
    a[1][2] = a[2][3] = a[3][4] = a[4][5] = a[5][1] = 'e';
    a[1][3] = a[2][4] = a[3][5] = a[4][1] = a[5][2] = 'i';
    a[1][4] = a[2][5] = a[3][1] = a[4][2] = a[5][3] = 'o';
    a[1][5] = a[2][1] = a[3][2] = a[4][3] = a[5][4] = 'u';
    for(i = 6; i <= n; i++){
        a[i][1] = 'a';
        a[i][2] = 'e';
        a[i][3] = 'i';
        a[i][4] = 'o';
        a[i][5] = 'u';
    }
    for(j = 6; j <= m; j++){
        a[1][j] = 'a';
        a[2][j] = 'e';
        a[3][j] = 'i';
        a[4][j] = 'o';
        a[5][j] = 'u';
    }
    for(i = 6; i <= n; i++){
        for(j = 6; j <= m; j++){
            a[i][j] = 'b';
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout<< a[i][j];
        }
    }
}