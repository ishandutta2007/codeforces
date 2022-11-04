#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define M 200010

using namespace std;

int n, m;

int S[M], Sz[M], Nx[M], Pr[M], col[M];

vector <int> Ans1, Ans2, Ans3;

vector <int> V[M];

void Do(int x, int y, int z) {
    Ans1.push_back(x);
    Ans2.push_back(y);
    Ans3.push_back(z);
}

int main() {
    int tot = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        tot += x;
        Sz[i] = x;
        for(int j = 1; j <= x; j++) {
            int k;
            scanf("%d", &k);
            V[k].push_back(i);//hsh[i].push_back(k);
        }
    }
    int a = tot / n, b = tot % n;
    int t1 = 1, t2 = 1;
    for(int i = 1; i <= n; i++)
        if(Sz[i] > a && b) {
            b--;
            S[i] = a + 1;
        } else S[i] = a;
    if(b) {
        for(int i = 1; i <= n && b; i++)
            if(S[i] != a + 1) S[i] = a + 1, b--;
    }
    int lst = 0;
    for(int i = 1; i <= n + 1; i++)
        if(Sz[i] < S[i] || i == n + 1) {
            Nx[lst] = i;
            Pr[i] = lst;
            lst = i;
        }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < V[i].size(); j++)
            col[V[i][j]] = i;
        int t = Nx[0];
        for(int j = 0; j < V[i].size(); j++)
            if(Sz[V[i][j]] > S[V[i][j]]) {
                while(t != n + 1) {
                    if(col[t] != i) {
                        Do(V[i][j], t, i);
                        Sz[V[i][j]]--;
                        Sz[t]++;
                        if(Sz[t] == S[t]) {
                            Pr[Nx[t]] = Pr[t];
                            Nx[Pr[t]] = Nx[t];
                        }
                        t = Nx[t];
                        break;
                    }
                    t = Nx[t];
                }
            }
    }
    printf("%d\n", Ans1.size());
    for(int i = 0; i < Ans1.size(); i++) printf("%d %d %d\n", Ans1[i], Ans2[i], Ans3[i]);
    return 0;
}