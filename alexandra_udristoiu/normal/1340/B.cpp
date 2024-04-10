#include<iostream>
using namespace std;
int n, k, i, j, ii;
int d[2005][2015], ok[2005][11];
char a[10][9] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char v[2005][10];
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        for(j = 0; j < 10; j++){
            for(ii = 0; ii < 7; ii++){
                if(a[j][ii] == '0' && v[i][ii] == '1'){
                    ok[i][j] = -1;
                    break;
                }
                else{
                    if(a[j][ii] == '1' && v[i][ii] == '0'){
                        ok[i][j]++;
                    }
                }
            }
        }
    }
    d[n + 1][0] = 1;
    for(i = n; i >= 1; i--){
        for(j = 0; j <= k; j++){
            if(d[i + 1][j] == 1){
                for(ii = 0; ii < 10; ii++){
                    if(ok[i][ii] != -1){
                        d[i][j + ok[i][ii] ] = 1;
                    }
                }
            }
        }
    }
    if(d[1][k] == 0){
        cout<< -1;
        return 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 9; j >= 0; j--){
            if(ok[i][j] != -1 && k >= ok[i][j] && d[i + 1][ k - ok[i][j] ] == 1){
                cout<< j;
                k -= ok[i][j];
                break;
            }
        }
    }
}