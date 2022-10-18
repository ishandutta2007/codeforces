/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e5;

int k, fa[N + 10], ans[N + 10][5], e[N + 10][5];
char opt[10], str[N + 10];

void dfs(int u, int p) {
    fa[u] = p;
    if (u <= (1 << (k - 1))) {
        if (str[u] == '?') ans[u][0] = 2;
        else if (str[u] == '0') ans[u][0] = 0;
        else ans[u][0] = 1;
        return (void)(ans[u][1] = (ans[u][0] + 2) / 2);
    }
    e[u][0] = (1 << k) - (((1 << k) - u) << 1 | 1), e[u][1] = (1 << k) - (((1 << k) - u) << 1), dfs(e[u][0], u), dfs(e[u][1], u); 
    if (str[u] == '?') ans[u][0] = 2;
    else if (str[u] == '0') ans[u][0] = 0;
    else ans[u][0] = 1;
	if (ans[u][0] == 2) ans[u][1] = ans[e[u][0]][1] + ans[e[u][1]][1]; 
	else ans[u][1] = ans[e[u][ans[u][0]]][1]; 
}

void work(int u, int p) {
    ans[u][0] = p;
    if (u <= (1 << (k - 1))) ans[u][1] = (ans[u][0] + 2) / 2, u = fa[u];
    while (u) {
        if (ans[u][0] == 2) ans[u][1] = ans[e[u][0]][1] + ans[e[u][1]][1]; 
        else ans[u][1] = ans[e[u][ans[u][0]]][1]; 
        u = fa[u]; 
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = 1, q; T--;) {
        fr(k), scanf("%s", str + 1), dfs((1 << k) - 1, 0), fr(q);
        for (int i = 1, x; i <= q; i++) {
            fr(x), scanf("%s", opt);
            if (opt[0] == '?') work(x, 2);
            else if (opt[0] == '0') work(x, 0);
            else work(x, 1);
            printf("%d\n", ans[(1 << k) - 1][1]);
        }
    }
    return 0;
}