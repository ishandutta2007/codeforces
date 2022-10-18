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

const int N = 2e5;

int a[N + 10], ans[N + 10];
bool vis[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        ans[0] = 0;
        for (int i = 1; i <= n; i++) vis[i] = ans[i] = 0;
        for (int i = 1; i <= n; i++) {
            fr(a[i]);
            if (vis[a[i]] == 0) ans[i] = a[i], vis[a[i]] = 1, ans[0]++;
        }
        int pos = 1;
        for (int i = 1; i <= n; i++)
            if (ans[i] == 0) {
                while (vis[pos]) pos++;
                ans[i] = pos, pos++;
            }
        pos = -1;
        for (int i = 1; i <= n; i++)
            if (ans[i] == i) {
                if (pos == -1) pos = i;
                else swap(ans[i], ans[pos]);
            }
        if (pos != -1) {
            for (int i = 1; i <= n; i++)
                if (a[i] == a[pos]) {
                    swap(ans[i], ans[pos]);
                    break;
                }
        }
        printf("%d\n", ans[0]);
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}