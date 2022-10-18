/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 26;

char str[N + 10];
int vis[N + 10];
bool vis1[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1), memset(vis, 0, sizeof(vis)), memset(vis1, 0, sizeof(vis1));
        int n = strlen(str + 1), s = 0, tot = 1;
        for (int i = 1; i <= n; i++)
            if (str[i] == 'a') {
                s = i;
                vis[0] = i;
                vis1[i] = 1;
                break;
            }
        if (s == 0) {
            puts("NO");
            continue;
        }
        if (s != 1) {
            if (vis[str[s - 1] - 'a'] != 0) {
                puts("NO");
                goto cat;
            }
            vis[str[s - 1] - 'a'] = s - 1;
        }
        if (s != n) {
            if (vis[str[s + 1] - 'a'] != 0) {
                puts("NO");
                goto cat;
            }
            vis[str[s + 1] - 'a'] = s + 1;
        }
        for (char i = 'b'; i <= 'z'; i++) {
            if (tot == n) break;
            if (vis[i - 'a'] == 0) {
                puts("NO");
                goto cat;
            }
            tot++;
            s = vis[i - 'a'];
            vis1[s] = 1;
            if (s != 1) {
                if (vis[str[s - 1] - 'a'] != 0 && vis1[s - 1] == 0) {
                    puts("NO");
                    goto cat;
                }
                vis[str[s - 1] - 'a'] = s - 1;
            }
            if (s != n) {
                if (vis[str[s + 1] - 'a'] != 0 && vis1[s + 1] == 0) {
                    puts("NO");
                    goto cat;
                }
                vis[str[s + 1] - 'a'] = s + 1;
            }
        }
        puts("YES");
    cat:;
    }
    return 0;
}