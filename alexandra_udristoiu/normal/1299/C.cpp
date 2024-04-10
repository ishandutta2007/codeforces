#include<iostream>
#include<cstdio>
#include<iomanip>
#define x first
#define y second
#define DIM 1000005
#define pll pair<long long, long long>
using namespace std;
int n, i, x, u, j;
long long sum[DIM];
pll v[DIM], pct;
double val;
long long det(pll p1, pll p2, pll p3){
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
int cmp(pll a, pll b){
    return det(pct, a, b) > 0;
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
        v[i] = make_pair(i, sum[i]);
    }
    pct = make_pair(0, 0);
    u = 1;
    for(i = 2; i <= n; i++){
        while(u != 0 && det(v[u - 1], v[u], v[i]) < 0){
            u--;
        }
        v[++u] = v[i];
    }
    for(i = 1; i <= u; i++){
        val = (v[i].y - v[i - 1].y) * 1.0 / (v[i].x - v[i - 1].x);
        for(j = v[i - 1].x + 1; j <= v[i].x; j++){
            printf("%0.9f ", val);
        }
    }
}