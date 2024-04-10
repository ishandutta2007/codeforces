#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;

int N, M, K;
int mat[MAXN][MAXN];
int a[MAXN][MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)     
            scanf("%d", mat[i] + j);
}

vector <int> f(int mask) {
    vector <int> res;
    for (int i = 0; i < M; i++) 
        res.push_back(mask >> i & 1);
    return res;
}

int calc(const vector <int> &V) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < M; j++) {
            x += a[i][j] ^ V[j];
            y += a[i][j] ^ V[j] ^ 1;
        }
        res += min(x, y);
    }
    return res;
}

int solve() {
    memcpy(a, mat, sizeof a);
    if (N < M) {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                a[j][i] = mat[i][M - j - 1];
        swap(N, M);
    }
    int sol = N * M;
    if (N > K) 
        for (int i = 0; i < N; i++) 
            sol = min(sol, calc(vector <int> (a[i], a[i] + M)));
    else
        for (int i = 0; i < 1 << M; i++) 
            sol = min(sol, calc(f(i)));
    if (sol > K) sol = -1;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}