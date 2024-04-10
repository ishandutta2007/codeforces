#include<iostream>
using namespace std;
int i, j, x, y, ii, jj;
int ff[12];
long long n, sol, d[12][20], c[20][20];
int main(){
    cin>> n;
    while(n != 0){
        ff[n % 10]++;
        n /= 10;
    }
    for(i = 0; i < 10; i++){
        if(ff[i] > 0){
            x++;
        }
        y += ff[i];
    }
    c[0][0] = 1;
    for(i = 1; i <= 18; i++){
        c[i][0] = 1;
        for(j = 1; j <= i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for(ii = x; ii <= y; ii++){
        for(i = 0; i <= 10; i++){
            for(j = 0; j <= ii; j++){
                d[i][j] = 0;
            }
        }
        d[0][ii] = 1;
        for(i = 0; i <= 9; i++){
            if(ff[i] == 0){
                for(j = 0; j <= ii; j++){
                    d[i + 1][j] = d[i][j];
                }
                continue;
            }
            for(j = 1; j <= min(ff[i], ii); j++){
                for(jj = 0; jj <= ii - j; jj++){
                    if(i > 0){
                        d[i + 1][jj] += d[i][j + jj] * c[j + jj][j];
                    }
                    else{
                        d[i + 1][jj] += d[i][j + jj] * c[j + jj - 1][j];
                    }
                }
            }
        }
        sol += d[10][0];
    }
    cout<< sol;
}