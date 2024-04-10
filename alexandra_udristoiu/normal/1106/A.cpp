#include<iostream>
using namespace std;
int n, i, j, sol;
char a[505][505];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin>> a[i][j];
        }
    }
    for(i = 2; i < n; i++){
        for(j = 2; j < n; j++){
            if(a[i][j] == 'X' && a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X' && a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X'){
                sol++;
            }
        }
    }
    cout<< sol;
}