#include<iostream>
using namespace std;
int t, n, i, j;
int d[3005][3005], v[3005], num[3005];
long long sol;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        sol = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                num[j] = 0;
            }
            for(j = i + 1; j <= n; j++){
                num[ v[j] ]++;
            }
            for(j = i - 1; j >= 1; j--){
                d[i][j] = d[i][j + 1] + num[ v[j] ];
            }
        }
        for(i = 1; i <= n; i++){
            for(j = i + 1; j <= n; j++){
                if(v[i] == v[j]){
                    sol += d[j][i + 1];
                }
            }
        }
        cout<< sol <<"\n";
    }
}