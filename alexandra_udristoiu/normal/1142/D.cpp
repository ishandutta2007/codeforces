#include<iostream>
#include<cstring>
#define DIM 100005
using namespace std;
int n, i, a, b, c, na, nb, nc, t, sum[20];
char s[DIM];
long long d[2][12][12][12], sol;
int calc(int p, int u){
    if(p <= u){
        return (sum[u] - sum[ max(p - 1, 0) ] + 11) % 11;
    }
    else{
        return (sum[u] + sum[10] - sum[p - 1] + 11) % 11;
    }
}
int main(){
    for(i = 1; i < 11; i++){
        sum[i] = (sum[i - 1] + i) % 11;
    }
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 1; i <= n; i++){
        s[i] -= '0';
    }
    for(i = 1; i < n; i++){
        if(s[i] != 0){
            d[t][1][ s[i] ][9]++;
        }
        for(a = 0; a < 11; a++){
            for(b = 0; b < 11; b++){
                for(c = 0; c < 11; c++){
                    sol += d[t][a][b][c];
                    if(s[i + 1] < b && d[t][a][b][c] != 0){
                        na = (c + 1) % 11;
                        if(a != b){
                            nb = (c + calc(a, b - 1) + s[i + 1] + 1) % 11;
                        }
                        else{
                            nb = (c + s[i + 1] + 1) % 11;
                        }
                        nc = (calc(a, c) + c) % 11;
                        d[1 - t][na][nb][nc] += d[t][a][b][c];
                    }
                    d[t][a][b][c] = 0;
                }
            }
        }
        t = 1 - t;
    }
    if(s[n] != 0){
        d[t][1][ s[i] ][9]++;
    }
    for(a = 0; a < 11; a++){
        for(b = 0; b < 11; b++){
            for(c = 0; c < 11; c++){
                sol += d[t][a][b][c];
            }
        }
    }
    cout<< sol;
}