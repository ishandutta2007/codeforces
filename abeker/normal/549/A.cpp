#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 55;

int N, M;
char mat[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

int solve() {
    int sol = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 1; j++) {
            string s = "";
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    s += mat[i + k][j + l];
            sort(s.begin(), s.end());
            sol += s == "acef";
        }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}