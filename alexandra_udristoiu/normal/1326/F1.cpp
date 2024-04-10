#include<iostream>
using namespace std;
int n, i, j, ii, x, y, st, st2, k, k2, val;
int d1[ (1 << 14) + 1][(1 << 6) + 1][15], d2[ (1 << 14) + 1][(1 << 6) + 1][15];
long long d[(1 << 13) + 2], num[(1 << 14) + 5];
int viz[16], v[10];
char a[16][16];
void backt(int p, int t, int st, int x){
    if(p == n / 2 + 1){
        d1[st][x][ v[p - 1] ]++;
       // return;
    }
    if(p == n - n / 2 + 1){
        d2[st][x][ v[1] ]++;
        return;
    }
    int y;
    for(int i = 0; i < n; i++){
        if(viz[i] == 0){
            v[p] = i;
            viz[i] = 1;
            y = x;
            if(p != 1){
                y += (1 << (p - 2) ) * a[ v[p - 1] ][ v[p] ];
            }
            backt(p + 1, t, st + (1 << i), y );
            viz[i] = 0;
        }
    }
}
int main(){
    cin>> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin>> a[i][j];
            a[i][j] -= '0';
        }
    }
    backt(1, 1, 0, 0);
   // backt(1, 2, 0);
    k = n / 2 - 1;
    k = (1 << k);
    k2 = n - n / 2 - 1;
    k2 = (1 << k2);
    for(i = 1; i < (1 << n); i++){
        num[i] = i % 2 + num[i / 2];
    }
    for(i = 0; i < k; i++){
        for(ii = 0; ii < (1 << n); ii++){
            if(num[ii] != n / 2){
                continue;
            }
            for(x = 0; x < n; x++){
                if(d1[ii][i][x] != 0){
                    for(y = 0; y < n; y++){
                        if( ( (ii >> y) & 1) == 0){
                            for(j = 0; j < k2; j++){
                                val = i + a[x][y] * k + j * k * 2;
                                d[val] += d1[ii][i][x] * 1LL * d2[(1 << n) - 1 - ii][j][y];
                            }
                        }
                    }
                }
            }
        }
    }
    for(i = 0; i < (1 << (n - 1) ); i++){
        cout<< d[i] <<" ";
    }
}