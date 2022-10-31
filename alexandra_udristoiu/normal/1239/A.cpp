#include<iostream>
#define mod 1000000007
using namespace std;
int n, i, j, a, b, c, m, sol;
int d[100005][4];
int main(){
    cin>> n >> m;
    if(n * m == 1){
        cout<< 2;
        return 0;
    }
    d[2][0] = d[2][1] = d[2][2] = d[2][3] = 1;
    for(i = 3; i <= max(n, m); i++){
        for(j = 0; j < 4; j++){
            a = j / 2;
            b = j % 2;
            if(a == b){
                d[i][j] = d[i - 1][ (1 - a) * 2 + a];
            }
            else{
                d[i][j] = (d[i - 1][2 + a] + d[i - 1][a]) % mod;
            }
        }
    }
    for(i = 0; i < 4; i++){
        sol = (sol + d[n][i]) % mod;
        sol = (sol + d[m][i]) % mod;
    }
    if(n != 1 && m != 1){
        sol = (sol - 2 + mod) % mod;
    }
    cout<< sol;
}