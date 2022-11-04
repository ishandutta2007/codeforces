#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int a, b, c, d, e, f;
    node() {}
    node(int _1, int _2, int _3, int _4, int _5, int _6) {a = _1, b = _2, c = _3, d = _4, e = _5, f = _6;}
};

node Pr[205][205][6][4];

bool C[205][205][6][4];

void upd(int i, int j, int k, int l, int a, int b) {
    if(i + a > 200 || j + b > 200) return;
    int ii = i + a, jj = j + b, kk = k + 1, ll = l + (a > b);
    C[ii][jj][kk][ll] = 1;
    Pr[ii][jj][kk][ll] = node(i, j, k, l, a, b);
}

void Do(int a, int b, int c, int d) {
    if(c == 0) return;
    node tmp = Pr[a][b][c][d];
    Do(tmp.a, tmp.b, tmp.c, tmp.d);
    printf("%d:%d ", tmp.e, tmp.f);
}

int main() {
    memset(C, 0, sizeof C);
    C[0][0][0][0] = 1;
    for(int i = 0; i <= 200; i++)
        for(int j = 0; j <= 200; j++)
            for(int k = 0; k < 5; k++)
                for(int l = 0; l < 4 && l <= k; l++) if(C[i][j][k][l]) {
                    int wa = l, wb = k - l;
                    if(wa == 3 || wb == 3) continue;
                    int thres = k <= 3 ? 25 : 15;
                    for(int a = 0; a <= thres - 3; a++) upd(i, j, k, l, a, thres);
                    for(int b = 0; b <= thres - 3; b++) upd(i, j, k, l, thres, b);
                    for(int a = thres; a <= 200; a++) upd(i, j, k, l, a, a - 2);
                    for(int b = thres; b <= 200; b++) upd(i, j, k, l, b - 2, b);
                }
    int m;
    scanf("%d", &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int mx = -5, v1 = -1, v2 = -1, ans1, ans2;
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 4; j++) if(C[a][b][i][j]) {
                int wa = j, wb = i - j, w = wa - wb;
                if(wa <= 2 && wb <= 2) continue; //!!!
                if(w > mx) {
                    mx = w;
                    v1 = i;
                    v2 = j;
                    ans1 = wa;
                    ans2 = wb;
                }
            }
        if(v1 == -1) {
            puts("Impossible");
            continue;
        }
        printf("%d:%d\n", ans1, ans2);
        Do(a, b, v1, v2);
        putchar('\n');
    }
    return 0;
}