#include<iostream>
#include<cstdio>
using namespace std;
int n, q, ii1, jj1, ii2, jj2, c, t, i, ii, j;
int a[11][105][105];
int sol[100005];
struct str{
    int x, y, s;
};
str v[100005];
int modul(int x){
    if(x >= c){
        return x - c;
    }
    return x;
}
int main(){
     scanf("%d%d%d", &n, &q, &c);
    c++;
    for(i = 1; i <= n; i++){
         scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].s);
    }
    for(ii = 0; ii < c; ii++){
        for(i = 1; i <= n; i++){
            a[ii][ v[i].x ][ v[i].y ] += modul(ii + v[i].s);
        }
        for(i = 1; i <= 100; i++){
            for(j = 1; j <= 100; j++){
                a[ii][i][j] = a[ii][i][j] + a[ii][i - 1][j] + a[ii][i][j - 1] - a[ii][i - 1][j - 1];
            }
        }
    }
    for(i = 1; i <= q; i++){
        scanf("%d%d%d%d%d", &t, &ii1, &jj1, &ii2, &jj2);
        t %= c;
        sol[i] =  a[t][ii2][jj2] - a[t][ii2][jj1 - 1] - a[t][ii1 - 1][jj2] + a[t][ii1 - 1][jj1 - 1];
    }
    for(i = 1; i <= q; i++){
        printf("%d\n", sol[i]);
    }
    return 0;
}