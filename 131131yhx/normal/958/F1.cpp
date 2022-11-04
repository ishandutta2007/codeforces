#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, X[111], Y[111], S[111];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &Y[i]);
    int tot = 0;
    for(int i = 1; i <= m; i++) tot += Y[i];
    for(int i = 1; i + tot - 1 <= n; i++) {
        memset(S, 0, sizeof S);
        for(int j = i; j < i + tot; j++)
            S[X[j]]++;
        int flag = 0;
        for(int j = 1; j <= m; j++) if(S[j] != Y[j]) flag = 1;
        if(!flag) return puts("YES"), 0;
    }
    puts("NO");
}