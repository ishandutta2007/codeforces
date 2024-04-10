#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 4000010
#define Inf 1000000007
#define PII pair <int, int>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

int n, m[2], T, X[2][M], F[2][M];

bool Pr[2][M];

vector <int> V, Ans1;

vector <PII> Ans2, Ans3;

void upd(int x, int y, int v, int p) {
    if(F[x][y] < v) {
        F[x][y] = v;
        Pr[x][y] = p;
    }
}

void Solve(int x, int y) {
    if(y) {
        Solve(Pr[x][y], y - 1);
        if(Pr[x][y] != x) {
            Ans1.push_back(V[y]);
            Ans2.push_back(PII(V[y] + max(0, T - F[x][y]), x));
        }
    } else {
        if(x) Ans1.push_back(0);
        Ans2.push_back(PII(T, x));
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m[0], &m[1], &T);
    n++;
    for(int i = 1; i <= m[0]; i++) scanf("%d", &X[0][i]), V.push_back(X[0][i]), V.push_back(X[0][i] + 1);
    for(int i = 1; i <= m[1]; i++) scanf("%d", &X[1][i]), V.push_back(X[1][i]), V.push_back(X[1][i] + 1);
    X[0][m[0] + 1] = n + 1;
    X[1][m[1] + 1] = n + 1;
    //sort(X[0] + 1, X[0] + m[0] + 1);
    //sort(X[1] + 1, X[1] + m[1] + 1);
    V.push_back(n);
    V.push_back(0);
    //for(int i = 0; i <= n; i++) V.push_back(i);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    memset(F, 200, sizeof F);
    F[0][0] = (F[1][0] = 0);
    int t[2] = {0, 0};
    for(int i = 0; i < V.size() - 1; i++) {
        while(X[0][t[0]] < V[i + 1]) t[0]++;
        while(X[1][t[1]] < V[i + 1]) t[1]++;
        for(int j = 0; j < 2; j++) if(F[j][i] >= 0) {
            if(X[j][t[j]] == V[i + 1]) {
                int tmp = F[j][i] + V[i + 1] - V[i];
                if(tmp <= T) continue;
                upd(j, i + 1, tmp - T, j);
                if(X[!j][t[!j]] != V[i + 1]) upd(!j, i + 1, min(tmp - T, T), j);
            } else {
                upd(j, i + 1, F[j][i] + V[i + 1] - V[i], j);
                if(X[!j][t[!j]] != V[i + 1]) upd(!j, i + 1, min(F[j][i] + V[i + 1] - V[i], T), j);
            }
        }
    }
    int tot[2];
    tot[0] = m[0];
    tot[1] = m[1];
    for(int i = 0; i < 2; i++)
        if(F[i][V.size() - 1] >= 0) {
            Solve(i, V.size() - 1);
            puts("Yes");
            printf("%d\n", Ans1.size());
            for(int j = 0; j < Ans1.size(); j++) printf("%d ", Ans1[j]);
            Ans2.push_back(PII(n + T - 1, !Ans2.back().second));
            for(int i = 0; i < Ans2.size() - 1; i++)
                for(int j = Ans2[i].first; j + T <= Ans2[i + 1].first; j += T) {
                    if(tot[Ans2[i].second]-- > 0) Ans3.push_back(PII(j, Ans2[i].second));
                    else break;
                }
            printf("\n%d\n", Ans3.size());
            for(int i = 0; i < Ans3.size(); i++) printf("%d %d\n", Ans3[i].first, Ans3[i].second + 1);
            return 0;
        }
    puts("No");
    return 0;
}