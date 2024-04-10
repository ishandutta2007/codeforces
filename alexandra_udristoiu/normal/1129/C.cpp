#include<iostream>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n, i, j, u, ii, x, sol;
int v[3005], d[3005][3005], c[3005], a[14][3005], pm[3005];
struct str{
    int ii, jj, p;
};
str w[3005];
int cmp(str a, str b){
    if(a.ii == b.ii){
        return a.jj < b.jj;
    }
    return a.ii < b.ii;
}
int calc(int ii, int jj){
    int i, j;
    for(i = ii, j = jj; i <= n && j <= n; i++, j++){
        if(v[i] != v[j]){
            break;
        }
    }
    return i - ii;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        d[i + 1][i] = 1;
    }
    for(i = n; i >= 1; i--){
        for(j = i; j <= n; j++){
            x = 0;
            for(ii = i; ii <= min(i + 3, j); ii++){
                x = x * 2 + v[ii];
                if(ii != i + 3 || (x != 3 && x != 5 && x != 14 && x != 15) ){
                    d[i][j] = (d[i][j] + d[ii + 1][j]) % mod;
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        a[0][i] = v[i];
    }
    for(ii = 1; (1 << (ii - 1) ) < n; ii++){
        for(i = 1; i <= n; i++){
            w[i].p = i;
            w[i].ii = a[ii - 1][i];
            if(i + (1 << (ii - 1) ) <= n){
                w[i].jj = a[ii - 1][ i + (1 << (ii - 1) ) ];
            }
            else{
                w[i].jj = -1;
            }
        }
        sort(w + 1, w + n + 1, cmp);
        w[0].ii = -1;
        for(i = 1; i <= n; i++){
            if(w[i].ii == w[i - 1].ii && w[i].jj == w[i - 1].jj){
                a[ii][ w[i].p ] = a[ii][ w[i - 1].p ];
            }
            else{
                a[ii][ w[i].p ] = i;
            }
        }
    }
    for(i = 1; i <= n; i++){
        pm[i] = i + 1;
    }
    for(i = 1; i <= n; i++){
        while(u > 0 && w[ c[u] ].p > w[i].p){
            u--;
        }
        if(u != 0){
            x = calc(w[ c[u] ].p, w[i].p);
            for(j = w[i].p; j < w[i].p + x; j++){
                pm[j] = min(pm[j], w[i].p);
            }
        }
        c[++u] = i;
    }
    u = 0;
    for(i = n; i >= 1; i--){
        while(u > 0 && w[ c[u] ].p > w[i].p){
            u--;
        }
        if(u != 0){
            x = calc(w[ c[u] ].p, w[i].p);
            for(j = w[i].p; j < w[i].p + x; j++){
                pm[j] = min(pm[j], w[i].p);
            }
        }
        c[++u] = i;
    }
    for(i = 1; i <= n; i++){
        for(j = pm[i] - 1; j >= 1; j--){
            sol = (sol + d[j][i]) % mod;
        }
        cout<< sol <<"\n";
    }
}