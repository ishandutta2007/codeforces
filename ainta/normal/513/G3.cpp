#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[12100];
vector<double>P[12100];
double R[12100], TP[12100], PP[11000];
int n, K, w[110], cnt, L[110];
void Inverse(int b, int e){
    int i;
    for (i = b; i <= (b + e) / 2; i++){
        swap(L[i], L[b + e - i]);
    }
}
int Num(int a, int b){
    return a * 101 + b;
}
int main(){
    int i, j, k, l, c1, c2, x, ti, tj;
    double t, Res = 0.0;
    scanf("%d%d", &n, &K);
    for (i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        L[i] = i;
    }
    t = 1.0 / (n*(n + 1) / 2);
    for (i = 1; i <= n; i++){
        for (j = i + 1; j <= n; j++){
            c1 = Num(i, j);
            for (k = 1; k <= n; k++){
                for (l = k; l <= n; l++){
                    ti = i, tj = j;
                    if (k <= i && i <= l) ti = k + l - i;
                    if (k <= j && j <= l)tj = k + l - j;
                    PP[Num(ti, tj)] += t;
                }
            }
            for (k = 1; k <= 10200; k++){
                if (PP[k] > 1e-9){
                    E[c1].push_back(k);
                    P[c1].push_back(PP[k]);
                }
                PP[k] = 0.0;
            }
        }
    }
    for (i = 1; i <= n; i++){
        for (j = i + 1; j <= n; j++){
            if (w[i] < w[j])R[Num(j, i)] = 1.0;
            else R[Num(i, j)] = 1.0;
        }
    }
    if (K > 1000)K = 1000;
    while (K--){
        for (i = 1; i <= n; i++){
            for (k = i + 1; k <= n; k++){
                c1 = Num(i, k);
                TP[c1] = 0.0;
                for (j = 0; j < E[c1].size(); j++){
                    x = E[c1][j];
                    TP[c1] += R[x] * P[c1][j];
                }
                TP[Num(k, i)] = 1.0 - TP[c1];
            }
        }
        for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (i != j)R[Num(i, j)] = TP[Num(i, j)];
    }
    for (i = 1; i < n; i++){
        for (j = i + 1; j <= n; j++){
            Res += R[Num(i, j)];
        }
    }
    printf("%.11lf\n", Res);
    return 0;
}