#include<iostream>
#include<cstring>
#define mod 998244353
using namespace std;
int n, i, j, lg, x, m, sol;
char t[3005], s[3005];
int d[3005][3005];
int modul(int x){
    if(x >= mod){
        return x - mod;
    }
    return x;
}
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    cin>> t + 1;
    m = strlen(t + 1);
    for(lg = n; lg > 1; lg--){
        if(lg >= m){
            d[1][lg] = modul(d[1][lg] + 1);
        }
        for(i = 1; i <= n - lg + 1; i++){
            j = i + lg - 1;
            if(i > m || t[i] == s[lg]){
                d[i + 1][j] = modul(d[i + 1][j] + d[i][j]);
            }
            if(j > m || t[j] == s[lg]){
                d[i][j - 1] = modul(d[i][j - 1] + d[i][j]);
            }
        }
    }
    if(m == 1){
        d[1][1] = modul(d[1][1] + 1);
    }
    for(i = 1; i <= n; i++){
        if(i > m || t[i] == s[1]){
            sol = modul(sol + d[i][i]);
        }
    }
    sol = modul(2 * sol);
    cout<< sol;
}