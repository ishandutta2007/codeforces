#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 300100;
const int oo = 1100000000;
const int M = 8;
int a[V][M], mi[V][1 << M], idx[1 << M];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i < (1 << m); ++i) {
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) {
                    idx[i] = j;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            mi[i][0] = oo;
            for (int j = 1; j < (1 << m); ++j) {
                int id = idx[j];
                mi[i][j] = min(mi[i][j ^ (1 << id)], a[i][id]);
            }
        }
        int rmi = -oo, ri = -1, rj = -1;
        for (int s = 0; s < (1 << m) / 2; ++s) {
            int rs = ((1 << m) - 1) ^ s;
            int idi = -1;
            int idj = -1;
            for (int i = 1; i <= n; ++i) {
                if (idi == -1 || mi[idi][s] < mi[i][s]) idi = i;
                if (idj == -1 || mi[idj][rs] < mi[i][rs]) idj = i;
            }
            if (rmi < min(mi[idi][s], mi[idj][rs])) {
                rmi = min(mi[idi][s], mi[idj][rs]);
                ri = idi;
                rj = idj;
            }
            //printf("%d %d %d %d %d %d\n", s, rs, idi, idj, mi[idi][s], mi[idj][rs]);
        }
       // printf("%d\n", rmi);
        printf("%d %d\n", ri, rj);
    }
    return 0;
}

/*
6 1
1
2
3
4
5
6
6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0
*/