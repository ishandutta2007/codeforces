#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void report(int x) {
    printf("%d\n", x);
    fflush(stdout);
}

int n, m;

int X[200010], Nx[200010], used[200010], t, lst = -1;

void Do_oppo() {
    scanf("%d", &lst);
    used[lst] = 1;
}

int main() {
    scanf("%d%d", &n, &m);
    n *= 2;
    memset(Nx, -1, sizeof Nx);
    memset(used, 0, sizeof used);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Nx[a] = b;
        Nx[b] = a;
    }
    scanf("%d", &t);
    if(t == 2) Do_oppo();
    for(int T = 1; T <= n / 2; T++) {
        if(lst != -1 && Nx[lst] != -1 && !used[Nx[lst]]) {
            report(Nx[lst]);
            used[Nx[lst]] = 1;
            if(t == 2 && T == n / 2) return 0;
            Do_oppo();
            continue;
        }
        int mx = -1, mxv = -1;
        for(int i = 1; i <= n; i++)
            if(!used[i] && Nx[i] != -1 && X[i] - X[Nx[i]] > mx) mxv = i, mx = X[i] - X[Nx[i]];
        if(mxv != -1) {
            report(mxv);
            used[mxv] = 1;
            if(t == 2 && T == n / 2) return 0;
            Do_oppo();
        } else {
            int mm = 0, v = -1;
            for(int i = 1; i <= n; i++)
                if(!used[i] && X[i] > mm) mm = X[i], v = i;
            report(v);
            used[v] = 1;
            if(t == 2 && T == n / 2) return 0;
            Do_oppo();
        }
    }
    return 0;
}