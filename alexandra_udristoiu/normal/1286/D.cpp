#include<iostream>
#include<algorithm>
#include<cstdio>
#define DIM 100005
#define mod 998244353
using namespace std;
int n, i, inv, nr, sol, ii, jj;
int v[DIM], x[DIM];
int p[DIM][2], aint[4 * DIM][2][2], a[DIM][2][2];
struct str{
    double t;
    int t2, ind, st0, st1;
};
str w[2 * DIM];
int cmp(str a, str b){
    return a.t < b.t;
}
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod][0][0] = p[st][0];
        aint[nod][1][1] = p[st][1];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int ii = 0; ii < 2; ii++){
                    for(int jj = 0; jj < 2; jj++){
                        aint[nod][i][j] = (aint[nod][i][j] + aint[2 * nod][i][ii] * 1LL * aint[2 * nod + 1][jj][j]) % mod;
                    }
                }
            }
        }
    }
}
void update(int nod, int st, int dr, int poz, int s0, int s1){
    if(st == dr){
        aint[nod][0][0] = p[st][0] * s0;
        aint[nod][1][1] = p[st][1] * s1;
    }
    else{
        int mid = (st + dr) / 2;
        if(poz <= mid){
            update(2 * nod, st, mid, poz, s0, s1);
        }
        else{
            update(2 * nod + 1, mid + 1, dr, poz, s0, s1);
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                aint[nod][i][j] = 0;
            }
        }
        for(int ii = 0; ii < 2; ii++){
            for(int jj = 0; jj < 2; jj++){
                if(a[mid][ii][jj] == 1){
                    for(int i = 0; i < 2; i++){
                        for(int j = 0; j < 2; j++){
                            aint[nod][i][j] = (aint[nod][i][j] + aint[2 * nod][i][ii] * 1LL * aint[2 * nod + 1][jj][j]) % mod;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    inv = mult(100, mod - 2);
    for(i = 1; i <= n; i++){
        scanf("%d%d%d", &x[i], &v[i], &p[i][1]);
        p[i][0] = 100 - p[i][1];
        p[i][0] = p[i][0] * 1LL * inv % mod;
        p[i][1] = p[i][1] * 1LL * inv % mod;
    }
    for(i = 1; i < n; i++){
        w[++nr] = {0, 0, i, 1, 0};
        w[nr].t = (x[i + 1] - x[i]) * 1.0 / (v[i] + v[i + 1]);
        w[nr].t2 = (x[i + 1] - x[i]) * 1LL * mult(v[i] + v[i + 1], mod - 2) % mod;
        if(v[i] < v[i + 1]){
            w[++nr] = {0, 0, i, 0, 0};
            w[nr].t = (x[i + 1] - x[i]) * 1.0 / (v[i + 1] - v[i]);
            w[nr].t2 = (x[i + 1] - x[i]) * 1LL * mult(v[i + 1] - v[i], mod - 2) % mod;
        }
        if(v[i] > v[i + 1]){
            w[++nr] = {0, 0, i, 1, 1};
            w[nr].t = (x[i + 1] - x[i]) * 1.0 / (v[i] - v[i + 1]);
            w[nr].t2 = (x[i + 1] - x[i]) * 1LL * mult(v[i] - v[i + 1], mod - 2) % mod;
        }
    }
    sort(w + 1, w + nr + 1, cmp);
    build(1, 1, n);
    for(i = 1; i <= n; i++){
        a[i][0][0] = a[i][0][1] = a[i][1][0] = a[i][1][1] = 1;
    }
    for(i = 1; i <= nr; i++){
        if(w[i].st0 == 0){
            update(1, 1, n, w[i].ind, 1, 0);
        }
        else{
            update(1, 1, n, w[i].ind, 0, 1);
        }
        if(w[i].st1 == 0){
            update(1, 1, n, w[i].ind + 1, 1, 0);
        }
        else{
            update(1, 1, n, w[i].ind + 1, 0, 1);
        }
        for(ii = 0; ii < 2; ii++){
            for(jj = 0; jj < 2; jj++){
                sol = (sol + aint[1][ii][jj] * 1LL * w[i].t2) % mod;
            }
        }
        a[ w[i].ind ][ w[i].st0 ][ w[i].st1 ] = 0;
        update(1, 1, n, w[i].ind, 1, 1);
        update(1, 1, n, w[i].ind + 1, 1, 1);
    }
    cout<< sol;
}