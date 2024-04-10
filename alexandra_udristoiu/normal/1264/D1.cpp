#include<iostream>
#include<cstring>
#define mod 998244353
using namespace std;
int n, i, j, nr, x, sol;
int d[2005], st[2005][2005], dr[2005][2005], sum[2005][2005];
char s[2005];
int modul(int x){
    if(x >= mod){
        return x - mod;
    }
    return x;
}
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    st[0][0] = 1;
    for(i = 1; i <= n; i++){
        if(s[i] != '('){
            st[i][0] = st[i - 1][0];
        }
        for(j = 1; j <= i; j++){
            if(s[i] == '('){
                st[i][j] = st[i - 1][j - 1];
            }
            else{
                if(s[i] == ')'){
                    st[i][j] = st[i - 1][j];
                }
                else{
                    st[i][j] = modul(st[i - 1][j] + st[i - 1][j - 1]);
                }
            }
        }
    }
    dr[n + 1][0] = sum[n + 1][0] = 1;
    for(i = n; i >= 1; i--){
        if(s[i] != ')'){
            dr[i][0] = dr[i + 1][0];
        }
        for(j = 1; j <= n - i + 1; j++){
            if(s[i] == '('){
                dr[i][j] = dr[i + 1][j];
            }
            else{
                if(s[i] == ')'){
                    dr[i][j] = dr[i + 1][j - 1];
                }
                else{
                    dr[i][j] = modul(dr[i + 1][j] + dr[i + 1][j - 1]);
                }
            }
        }
        for(j = n - i + 1; j >= 0; j--){
            sum[i][j] = modul(dr[i][j] + sum[i][j + 1]);
        }
    }
    for(i = 1; i <= n; i++){
        if(s[i] == '?'){
            nr++;
        }
        if(s[i] == '?' || s[i] == '('){
            for(j = 1; j <= i; j++){
                x = st[i - 1][j - 1] * 1LL * sum[i + 1][j] % mod;
                d[j] = modul(d[j] + x);
            }
        }
    }
    for(i = 1; i <= n; i++){
        d[i] -= d[i + 1];
        if(d[i] < 0){
            d[i] += mod;
        }
        sol = (sol + d[i] * 1LL * i) % mod;
    }
    cout<< sol;
}