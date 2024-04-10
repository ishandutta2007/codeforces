#include<iostream>
#define DIM 300005
using namespace std;
int n, i, ii, sum, jj, maxim;
int s[DIM], v[DIM], ff[DIM][2], nxt[DIM];
long long x, sol;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        while(x != 0){
            v[i] += x % 2;
            x /= 2;
        }
        s[i] = s[i - 1] + v[i];
    }
    for(i = n; i >= 1; i--){
        ff[i][0] = ff[i + 1][0];
        ff[i][1] = ff[i + 1][1];
        ff[i][ s[i] % 2]++;
    }
    for(i = 1; i <= n; i++){
        sum = 0;
        maxim = 0;
        for(ii = i; ii < min(n + 1, i + 128); ii++){
            maxim = max(maxim, v[ii]);
            sum += v[ii];
            if(sum % 2 == 0 && maxim <= sum / 2){
                sol++;
            }
        }
        sol += ff[ii][ s[i - 1] % 2 ];
    }
    cout<< sol;
}