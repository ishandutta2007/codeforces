#include <cstdio>
#include <algorithm>
 
#define fin stdin
#define fout stdout
//FILE *fin = fopen("a.in", "r"), *fout = fopen("a.out", "w");
 
struct myc {int x, y;} d[101][1 << 10][7];
 
#define INF 1000000
 
int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int mari[6] = {31, 37, 41, 43, 47, 53};
 
int ans[101], v[59];
 
int main() {
    int n;
    fscanf(fin, "%d", &n);
 
    for (int i = 0; i < (1 << 10); i++)
        for (int p = 0; p < 7; p++)
            d[0][i][p] = {INF, 0};
    d[0][0][0] = {0, 0};
    for (int i = 2; i < 59; i++) {
        for (int p = 0; p < 10; p++)
            if (i % prime[p] == 0)
                v[i] |= 1 << p;
        if (v[i] == 0) {
            while (i != mari[-v[i]])
                v[i]--;
            v[i]--;
        }
    }
    for (int r = 1; r <= n; r++) {
        int x;
        fscanf(fin, "%d", &x);
 
        int a = r, b = r - 1;
        for (int i = 0; i < (1 << 10); i++) {
            for (int j = 0; j < 7; j++) {
                d[a][i][j] = {d[b][i][j].x + x - 1, 1};
                for (int p = 2; p < 59; p++) {
                    if (v[p] < 0) {
                        if (-v[p] == j && d[b][i][j - 1].x + std::abs(x - p) < d[a][i][j].x)
                            d[a][i][j] = {d[b][i][j - 1].x + std::abs(x - p), p};
                    } else if ((i | v[p]) == i && d[b][i ^ v[p]][j].x + std::abs(x - p) < d[a][i][j].x)
                        d[a][i][j] = {d[b][i ^ v[p]][j].x + std::abs(x - p), p};
                }
            }
        }
    }
 
    int mask = 0, w = 0;
    for (int i = 0; i < (1 << 10); i++)
        for (int j = 0; j < 7; j++)
            if (d[n][i][j].x < d[n][mask][w].x)
                mask = i, w = j;
 
    //printf("%d\n", d[n][mask][w].x);
 
    for (int i = n; i > 0; i--) {
        ans[i] = d[i][mask][w].y;
        if (v[ans[i]] > 0)
            mask ^= v[ans[i]];
        else if (v[ans[i]] < 0)
            w--;
    }
 
    for (int i = 1; i <= n; i++)
        fprintf(fout, "%d ", ans[i]);
 
    fclose(fin);
    fclose(fout);
    return 0;
}